#include <stdio.h>	//BASIC INPUT/OUTPUT AND OTHER BASIC FUNCTION
#include <string.h>	//STRINGS FUNCTION
#include <stdlib.h>	//MEMORY ALLOCATION AND SYSTEM CLEAR
#include <unistd.h>	//PROCESS SUSPENSIONS (sleep)
#include <ctype.h>	//CHARACTER CLASSIFICATION FUNCTIONS (toupper & isdigit)
#include <conio.h>	//GETCH FUNCTION

#define MAX_CHAR 22
#define MAX 50
#define MASTERLIST "masterlist.dat"

typedef struct{
	char title[MAX_CHAR];						//hold value for title up to 22 bytes
	char author[MAX_CHAR];						//hold value for author up to 22 bytes
	char publication_year[6];					//hold value for year up to 6 bytes
	char price[MAX_CHAR];						//hold a value for price up to 22 bytes
	char* content;								//pointer variable for content
	char filename[MAX];							//hold a value for filename up to 50 bytes
	
	char newfilename[MAX];						//hold a value for newfilename up to 50 bytes
	char masterlistContent[MAX][7][MAX];		//a 3D array to hold the value of the masterlist
	char renameMark[2];							//a variable that hold the mark for raname (0 or 1)
	char choice;								//for choice variable
	FILE* file;									//file pointer
	int rows;									//hold the value for rows
	char holdValMasterlist[MAX];				//hold the value for masterlist ap to 50
	char *token;								//store the tokenize string
	int indexrow;								//hold the value for index row
}BOOK;


//GLOBAL DECLARATION
	BOOK book, printText;						//declare book and printText as struct BOOK
	int numStore, num;	
	
							
//FUNCTION PROTOTYPES
	//MAIN FEATURES
		void addBook();							//add book to masterlist and create a file for that particular book						
		void readBook();						//read the content of that particular book
		void bookDetails();						//display the details of that particular book
		void updateBook(int mark);				//update the content or details of that particular book
		void deleteBook();						//delete that particular book and in the masterlist
		void renameBook();						//rename the filename of that particular book
		void showList();						//show a list available book in the masterlist
		
	//FILE HANDLING
		void fileopen(BOOK* book, const char* mode);									//allow for opening filename in differrent modes
		void recordMasterlist(BOOK* book);												//record the details in the masterlist
		void updateMasterlist(BOOK* book, int mark);									//update the masterlist with the new book details
		int isExist(BOOK* book);														//check for the file existence
		void file_array(BOOK* book);													//convert file into array
		int isEmpty(BOOK* book);													 	//check is the file is empty or not
		
	//USER INPUT
		int TitleAndAuthor(BOOK* book);													//ask for author and title and check if it exist or not
		int askTitleValidate(BOOK* book, int mark);										//ask for title and validate it
		int askAuthorValidate(BOOK* book, int mark);									//ask for auhtor and validate it
		int askPubYearValidate(BOOK* book, int mark);									//ask for publication year and validate it
		int askPriceValidate(BOOK* book, int mark);										//ask for price and validate it
		void addContent(BOOK* book, int mark);											//ask for content
		
	//AESTHETIC
		void banner(const char* headerName);											//display banner
		void menu(BOOK* book);															//display menu options
		void invalid();																	//display invalid warning
		void noteText(int mark);														//display note text
		void adjustBoxDetails(BOOK* book, int mark, const char* label);					//automatically adjust the book details in the box
		void adjustContentInTheBox(char contentStr[10][1000], int lenstr, int page);	//automatically adjust the book content in the box
		void printPreviousInput(BOOK* book, int mark);									//display the previous input of the user
		int validate(BOOK* book, int mark);												//validate the user input
		
//**********************************************************************************************************************************************
//  START MAIN

int main(){
	
	banner("BOOK MANAGEMENT");		//display banner
	menu(&book);					//display menu options
	
	switch(book.choice){
		case '1':{ 					//ADD BOOK
			addBook();
			break;
		}
		case '2':{ 					//READ BOOK
			readBook();
			break;
		}
		case '3':{ 					//BOOK DETAILS
			bookDetails();
			break;
		}
		case '4':{ 					//UPDATE BOOK
			updateBook(1);
			break;
		}
		case '5':{ 					//DELETE BOOK
			deleteBook();
			break;
		}
		case '6':{ 					//RENAME BOOK
			renameBook();
			break;
		}
		case '7':{					//SHOWLIST
			showList();
			break;
		}
		case '8':{ 					//EXIT THE PROGRAMM
			break;
		}
		default:{ 					//DEFAULT
			invalid();
			main();
			break;
		}
	}
	
	return 0;	
}



//FUNCTIONS

/*********************************************************
* --------------------> ADD BOOK <------------------------
*
*	FUNCTION:
*		Add book in the masterlist and create file
*		from the given book title and author
**********************************************************/
	void addBook(){
		system("cls");			//clear the screen
		banner("ADD BOOK");		//display banner with the text "ADD BOOK"
		noteText(1);			//display note
		
	//call main function if true
		if(TitleAndAuthor(&book))						//ask for title and author, return 1 if the user choose to leave
			main();
			
		if(isExist(&book)){								//check if the title and author exist, if true then display the banner and return to menu
			banner("BOOK ALREADY EXIST");
			main();
		}
			
		if(askPubYearValidate(&book, 1))				//ask for publication year and return 1 if the user choose to leave
			main();
			
		if(askPriceValidate(&book, 1))					//ask for price and return 1 if the user choose to leave
			main();
		
		back:	
		//display option for adding content
			printf("\n\tEnter Book Content[Y/N]?:\n\n");
			printf("[Y] Yes\n");
			printf("[N] Add the book without content\n");
			printf("[ANY KEY] Change Book Details\n\n");
			printf("##################################################\n");
		
		printf("Enter Choice: ");
		book.choice = getchar();
		fflush(stdin);
		book.choice = toupper(book.choice);
		
		if(book.choice == 'Y'){
			system("cls");					//clear the screen
			banner("ADD BOOK");				//display banner with the text "ADD BOOK"
			addContent(&book, 1);			//add the content
			
			system("cls");
			printPreviousInput(&book, 4);
			goto back;
		}
		else if(book.choice == 'N'){
			fileopen(&book, "w");			//create the file with the filename concatenated from title and author
			fclose(book.file);
		}
		else if(book.choice == '0' || book.choice == ' '){
			system("cls");					//clear the screen
			main();
		}
		else
			addBook();						//call addbook funtion if the user choose to change the book details
		
		system("cls");						//clear the screen
		strcpy(book.renameMark, "0");		//add "0" for marking in rename
			
		recordMasterlist(&book);			//record the book details in masterlist file
		banner("Successfully added");	
		main();
	}


/*********************************************************
* --------------------> READ BOOK <------------------------
*
*	FUNCTION:
*		Display the book content by paragraph
**********************************************************/
	void readBook(){
		banner("READ BOOK");		//display banner with the text "READ BOOK"
		noteText(1);				//display note text
		
	//call main function if true
		if(TitleAndAuthor(&book))			//ask for title and author, return 1 if the user choose to leave		
			main();
			
		if(!isExist(&book)){				//check if the title and author exist, if true then display the banner and return to menu
			system("cls");
			banner("BOOK DOES NOT EXIST");
			main();
		}
		
		fileopen(&book, "r");				//open the file in read mode
		int page = 1, index = 0;
		char contentChar[1000], contentStr[10][1000];
		
		//Assign the content by paragraph in 2D array
			while(fgets(contentChar, 1000, book.file) != NULL){
				strcpy(contentStr[index], contentChar);
				index++;
			}
			
		fclose(book.file);
		
		//display the content of the book by paragraph
		while(1){
			system("cls");				//clear the screen
			banner("READ BOOK");		//display the banner with the text "READ BOOK"
			noteText(2);				//display note text number 2
			
			//if the book has no content yet, the statement will be executed
				if(isEmpty(&book) == 1){
					printf("|              No Content Yet              \t |\n", page);
					printf("##################################################\n");
					
					printf("         Enter to continue....");
					book.choice = getch();
					fflush(stdin);
					system("cls");
					main();
				}
				else
					printf("|                PARAGRAPH %d:             \t |\n", page);
				
			printf("|                                                |\n");
			int lenstr = strlen(contentStr[page-1]);		//hold the length value of one paragraph
			
			//if the book has only one paragraph content
				if(index == 1){
					adjustContentInTheBox(contentStr, lenstr, page);
					printf("|                                                |\n");
					printf("|                             [any key] EXIT     |\n");
					printf("##################################################\n");
					book.choice = getch();
					fflush(stdin);
					
					system("cls");
					main();	
				}
				else if(page == 1){ 	//display this statement if on the first paragraph
					adjustContentInTheBox(contentStr, lenstr, page);
					printf("|                                                |\n");
					printf("|                                  [2] Next      |\n");
					printf("##################################################\n");
					book.choice = getch();
					fflush(stdin);
					
					if(book.choice == '2'){
						page++;
						continue;
					}
					else{
						system("cls");
						main();	
					}
							
				}
				else if(page == index){	//display this statement if on the last paragraph
					adjustContentInTheBox(contentStr, lenstr, page);
					printf("|                                                |\n");
					printf("|      [1] Back                                  |\n");
					printf("##################################################\n");
					book.choice = getch();
					fflush(stdin);
					
					if(book.choice == '1'){
						page--;
						continue;
					}	
					else{
						system("cls");
						main();	
					}	
				}
				else{				//display this statement if on the middle paragraph
					adjustContentInTheBox(contentStr, lenstr, page);
					printf("|                                                |\n");
					printf("|      [1] Back                    [2] Next      |\n");
					printf("##################################################\n");
					book.choice = getch();
					fflush(stdin);
					
					if(book.choice == '2')
						page++;
					else if(book.choice == '1')
						page--;
					else{
						system("cls");
						main();
					}
				}
		}
		main();
	}
	

/*********************************************************
* ------------------> BOOK DETAILS <----------------------
*
*	FUNCTION:
*		Display the book details
**********************************************************/
	void bookDetails(){
		banner("BOOK DETAILS");				//display the banner with the text "BOOK DETAILS"
		noteText(1);						//display note text number 1
		
	//call main function if true
		if(TitleAndAuthor(&book))			//ask for title and author, return 1 if the user choose to leave
			main();
			
		if(isExist(&book) == 0){			//check if the title and author exist, if true then display the banner and return to menu
			system("cls");
			banner("BOOK DOES NOT EXIST");
			main();
		}
	
		//display the book details with the mechanics to auto adjust in the box
			system("cls");														//clear the screen
			banner("BOOK DETAILS");												//display banner with the text "BOOK DETAILS
			printf("|                                                |\n");
			adjustBoxDetails(&book, 1, "Title: ");								//display title
			adjustBoxDetails(&book, 2, "Author: ");								//display author			
			adjustBoxDetails(&book, 3, "Publication Year: ");					//display publication year
			adjustBoxDetails(&book, 4, "Price: $");								//display price
			printf("|                                                |\n");
			printf("##################################################\n");
			
		printf("           Press \"ENTER\" to continue...");
		book.choice = getch();
		system("cls");
		
		main();
	}


/*********************************************************
* ------------------> UPDATE BOOK <-----------------------
*
*	FUNCTION:
*		Display an option what to update, wether the book
*		content or the details. Update the choosen fields
*
* @paramms integer	- mark	- hold value for marking
**********************************************************/
	void updateBook(int mark){
		//execute this code for first call
			if(mark == 1){
				banner("UPDATE BOOK");					//display banner with the text "UPDATE BOOOK"
				noteText(1);							//display note text number 1
				
			//call main function if true
				if(TitleAndAuthor(&book))				//ask for title and author, return 1 if the user choose to leave
					main();
					
				if(!isExist(&book)){					//check if the title and author exist, if true then display the banner and return to menu
					system("cls");
					banner("BOOK DOES NOT EXIST");
					main();
				}
				strcpy(printText.author, book.author);								//<----|
				strcpy(printText.title, book.title);								//	   |
				strcpy(printText.publication_year, book.publication_year);			// copy the value to printText for displaying purpose
				strcpy(printText.price, book.price);								//<----|
			}
		
		system("cls");					//clear the screen
		banner("UPDATE BOOK");			//display the banner with the text "UPDATE BOOK"
		noteText(1);					//display note text number 1
		printf("|                                                |\n");
		printf("|                [1] Book Details                |\n");
		printf("|                [2] Book Content                |\n");
		printf("|                                                |\n");
		printf("##################################################\n");
		printf("Enter Choice: ");
		book.choice = getchar();
		fflush(stdin);
		
		if(book.choice == '1'){
		selectField:					//loop mark
			system("cls");
			banner("PREVIOUS CONTENT");
			noteText(3);
			printf("|                                                |\n");
			
			adjustBoxDetails(&book, 1, "Title: ");							//<-----|
			adjustBoxDetails(&book, 2, "Author: ");							//	    |
			adjustBoxDetails(&book, 3, "Publication Year: ");				//  display the previous book details and auto adjust to the box
			adjustBoxDetails(&book, 4, "Price: $");							//<-----|
			
			printf("|                                                |\n");
			printf("##################################################\n");
			printf("|            SELECT A FIELD TO UPDATE            |\n");
			printf("##################################################\n");
			printf("|                                                |\n");
			printf("|             [1] Title                          |\n");
			printf("|             [2] Author                         |\n");
			printf("|             [3] Publication Year               |\n");
			printf("|             [4] Price                          |\n");
			printf("|                                                |\n");
			printf("##################################################\n");
			
			int marking_only = 0;
			
			printf("Enter Choice: ");
			book.choice = getchar();
			fflush(stdin);
			system("cls");
			
			switch(book.choice){
				case '1':{
					banner("Update Title");
					noteText(1);
					printf("\nPrevious Title \"%s\"\n\n", printText.title);
					
					if(askTitleValidate(&book, 2)){
						strcpy(book.title, printText.title);
						goto selectField;
					}
					
					marking_only = 1;	
					break;
				}
				case '2':{
					banner("Update Author");
					noteText(1);
					printf("\nPrevious Author \"%s\"\n\n", printText.author);
					
					if(askAuthorValidate(&book, 2)){
						strcpy(book.author, printText.author);
						goto selectField;						
					}

					marking_only = 1;		
					break;
				}
				case '3':{
					banner("Update Publication Year");
					noteText(1);
					printf("\nPrevious Publication Year \"%s\"\n\n", printText.publication_year);
					
					if(askPubYearValidate(&book, 2))
						goto selectField;
						
					break;
				}
				case '4':{
					banner("Update Price");
					noteText(1);
					printf("\nPrevious Price \"%s\"\n\n", printText.price);
					
					if(askPriceValidate(&book, 2))
						goto selectField;
						
					break;
				}
				default:{
					updateBook(2);		//call update book function but this time, dont include the asking for title and author
				}
			}
			
			printf("\n\n[Any Key] Update more              [1] Save Update\n");
			printf("##################################################\n");
			printf("Enter Choice: ");
			book.choice = getchar();
			fflush(stdin);
			
			strcpy(book.masterlistContent[book.indexrow][0], book.title);	
			strcpy(book.masterlistContent[book.indexrow][1], book.author);		
			
			if(marking_only == 1){
				if(isExist(&book)){
					system("cls");
					banner("BOOK ALREADY EXIST");
					main();
				}
			}
			
			strcpy(book.masterlistContent[book.indexrow][0], book.title);				//<-----|
			strcpy(book.masterlistContent[book.indexrow][1], book.author);				//	copy the new information to the 3D array masterlist holder
			strcpy(book.masterlistContent[book.indexrow][2], book.publication_year);	//		|
			strcpy(book.masterlistContent[book.indexrow][3], book.price);				//<-----|
			
			if(book.choice == '1')
				updateMasterlist(&book, 0);				//update the masterlist with the new content
			else
				goto selectField;
				
		}
		else if(book.choice == '2'){
		AddOrUpdate:
			system("cls");					//clear the screen
			banner("UPDATE BOOK");			//display the banner with the text "UPDATE BOOK"
			noteText(1);					//display the note text number 1
			
			printf("|                                                |\n");
			printf("|                [1] Add Content                 |\n");
			printf("|                [2] Update Content              |\n");
			printf("|                                                |\n");
			printf("##################################################\n");
			
			printf("Enter Choice: ");
			book.choice = getchar();
			fflush(stdin);
			
			if(book.choice == '1'){
				system("cls");				//clear the screen	
				banner("ADD CONTENT");		//display the banner with the text "ADD CONTENT"
				noteText(1);				//display the note text number 1
				addContent(&book, 2);		//add content
				goto AddOrUpdate;
			}
			else if(book.choice == '2'){
				system("cls");				//clear the screen	
				
				char content[1000];
				int index, choice;;
				char contentChar[1000];
				char contentStr[10][1000];
				
			loopforinvalid:
				banner("UPDATE CONTENT");	//display the banner with the text "UPDATE CONTENT"
				
				//store the content in 2D array
					fileopen(&book, "r");		//open file in read mode
					
					index = 0;
					while(fgets(contentChar, 1000, book.file) != NULL){ 	//assign the book content by paragraph in 2D array
						strcpy(contentStr[index], contentChar);
						index++;
					}
					
					fclose(book.file);
					
				int page = 1;
				
				//diplay the previous content of the book
					for(int ind = 0; ind <index; ind++){
						int lenstr = strlen(contentStr[ind]);
						printf("|                                                |\n");
						printf("|                                                |\n");
						printf("| Paragraph %d:                                   |\n", ind+1);
						adjustContentInTheBox(contentStr, lenstr, page);
						page++;
					}
					
				printf("##################################################\n");
				printf("NOTE: \nEnter any key (except paragraph numbers) to go back\n\n");
				printf("Enter paragraph number to update: ");
				scanf("%d", &choice);
				fflush(stdin);
				
				if(choice == 0 || choice > page-1){
					system("cls");
					goto AddOrUpdate;
				}
				
				//ask for the word to be replace
					char replace[1000];
					printf("Enter word you want to replace: ");
					fgets(replace, 1000, stdin);
					replace[strcspn(replace, "\n")] = '\0';
					
				char *found = strstr(contentStr[choice -1], replace);
	
			    if(found == NULL) {		//error checking
			        printf("\n\tName not found in the original string.\n");
			        sleep(2);
			        system("cls");
			        goto loopforinvalid;
			    }
			    
			    //ask for the new word to replace
					char toreplace[1000];
					printf("Enter word to be replace: ");
					fgets(toreplace, 1000, stdin);
					toreplace[strcspn(toreplace, "\n")] = '\0';
					
				
				char new_content[100]; 	// Create a new array to store the modified string
			    int replace_len = strlen(replace);
			    int toreplace_len = strlen(toreplace);
			
			    // Copy the part before the found occurrence of replace
			    strncpy(new_content, contentStr[choice-1], found - contentStr[choice-1]);
			  
			    new_content[found - contentStr[choice-1]] = '\0';
			
			    // Concatenate the replacement string toreplace
			    strcat(new_content, toreplace);
			
			    // Concatenate the part after the found occurrence of replace
			    strcat(new_content, found + replace_len);
			    
			    strcpy(contentStr[choice -1], new_content);
			    
			    fileopen(&book, "w");		//update the book with the new content
			    for(int i = 0; i<index; i++){
			    	fprintf(book.file, "%s", contentStr[i]);
				}
				
				fclose(book.file);
			}
			else{
				system("cls");
				updateBook(2);
			}
		}
		else{
			system("cls");
			main();
		}
		system("cls");
		banner("Updated Successfully");
		main();
	}


/*********************************************************
* ------------------> DELETE BOOK <-----------------------
*
*	FUNCTION:
*		Delete the book in the masterlist and the file
*				itself
**********************************************************/
	void deleteBook(){
		banner("DELETE BOOK");			///display the banner with the text "DELETE BOOK"
		noteText(1);					//display note text number 1
		
		//call main function if true
		if(TitleAndAuthor(&book))		//ask for title and author, return 1 if the user choose to leave
			main();
			
		if(!isExist(&book)){			//check if the title and author exist, if true then display the banner and return to menu
			system("cls");
			banner("BOOK DOES NOT EXIST");
			main();
		}
		
		banner("DELETE BOOK");			//display the banner with the text "DELETE BOOK"
		noteText(3);					//display note text number 3
		
		printf("\n  **********************************************\n");
		printf("  |                                            |\n");
		printf("  | Are you sure you want to delete this book? |\n");
		printf("  |                                            |\n");
		printf("  |      [Y] Yes                [N] No         |\n");
		printf("  |                                            |\n");
		printf("  **********************************************\n");
		
		printf("\nEnter Choice: ");
		book.choice = getchar();
		book.choice = toupper(book.choice);
		fflush(stdin);
		system("cls");
		
		if(book.choice == 'Y'){
			if(remove(book.filename) != 0){			//remove the file of that particular book
				printf("\tSomething went wrong!!!\n\tfile not deleted\n");
				sleep(2);
				system("cls");
				main();
			}
			updateMasterlist(&book, 1);				//update the masterlist
			banner("SUCCESSFULLY REMOVE");
			main();
		}
		else if(book.choice == 'N')
			main();
		else
			deleteBook();
		
	}


/*********************************************************
* ------------------> RENAME BOOK <-----------------------
*
*	FUNCTION:
*		Rename the filename of that particular book
**********************************************************/
	void renameBook(){
		banner("RENAME BOOK");		//display the banner with the text "RENAME BOOK"
		noteText(1);				//display note text number 1
		
	//call main function if true
		if(TitleAndAuthor(&book))	//ask for title and author, return 1 if the user choose to leave
			main();
		
		if(!isExist(&book)){		//check if the title and author exist, if true then display the banner and return to menu
			system("cls");
			banner("BOOK DOES NOT EXIST");
			main();
		}
		
		banner("RENAME BOOK");		//display the banner with the text "RENAME BOOK"
		noteText(4);				//display note text number 1
	
	newfilename:	
		printf("\nEnter New Filename: ");
		fgets(book.newfilename, MAX, stdin);
		book.newfilename[strcspn(book.newfilename, "\n")] = '\0';
		
		if(strlen(book.newfilename) < 1){
			system("cls");
			main();
		}
		
		sprintf(book.newfilename, "%s.txt", book.newfilename);
		
		if(validate(&book, 5))		//validate the file name if it exist it will ask another filename
			goto newfilename;
		
		
		if(strcmp(book.newfilename, "0") == 0 || strcmp(book.newfilename, " ") == 0){
			system("cls");
			main();
		}
		
		if(rename(book.masterlistContent[book.indexrow][4], book.newfilename) != 0){
			printf("\n\tSomething went wrong!!!\n\tfile not renamed\n");
			sleep(2);
			system("cls");
			main();
		}
		
		strcpy(book.masterlistContent[book.indexrow][4], book.newfilename);
		strcpy(book.masterlistContent[book.indexrow][5], "1");
		
		updateMasterlist(&book, 0);			//update the masterlist with the new filename
		
		system("cls");
		banner("SUCCESSFULLY RENAMED");
		main();
	}



/*********************************************************
* --------------------> SHOWLIST <------------------------
*
*	FUNCTION:
*		Display the title by author with the mechanism to 
*			auto adjust in the box
*
**********************************************************/
	void showList(){
		
		banner("BOOKLIST");			//display the banner with the text "BOOKLIST"
		file_array(&book);			//Convert masterlist to array
		
		printf("|                                                |\n");
		//condition what to display if the booklist is empty
			if(book.rows == 0)
				printf("|              BOOKLIST IS EMPTY                 |\n");
			else if(book.rows > 0)
				printf("|\tNumber of %s %d\t\t\t |\n", (book.rows != 1) ? "books":"book", book.rows);
				
			printf("|                                                |\n");
		
		//loop to display each title by author of the book
			for(int index = 0; index < book.rows; index++){
			//auto adjust for design
				int lenstr, iteratenum;
				char numInd[3];
				sprintf(numInd, "%d", index);
				lenstr = strlen(book.masterlistContent[index][0]) + strlen(book.masterlistContent[index][1]) + strlen(numInd) + 8;
				iteratenum = 50 - lenstr;
				
			//print the title by author
				printf("| %d. %s by %s", index + 1, book.masterlistContent[index][0], book.masterlistContent[index][1]);
				
			//condition to auto adjust for design
				for(num = 0; num < iteratenum; num++){
					if(num == iteratenum - 1){
						printf("|\n");
						continue;
					}
					printf(" ");
				}
			}
			
		printf("|                                                |\n");
		printf("##################################################\n");
		printf("           Press \"ENTER\" to continue...");
		book.choice = getch();
		system("cls");	//clear the screen
		main();
	}



//******************************************** FILE HANDLING ********************************************************

/*********************************************************
* --------------> UPDATE MASTERLIST <---------------------
*
*	FUNCTION:
*		Update the masterlist
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark	- hold the value for marking
**********************************************************/
	void updateMasterlist(BOOK* book, int mark){
		book->file = fopen(MASTERLIST, "w");		//open masterlist in write mode
		
		//replace the newline character to null
			book->masterlistContent[book->indexrow][5][strcspn(book->masterlistContent[book->indexrow][5], "\n")]= '\0';
	
		//check if the rename mark equals to 0, then the filename will be the concatenated value of title and author, else the file name stays the same
			if(strcmp(book->masterlistContent[book->indexrow][5], "0") == 0){
				sprintf(book->masterlistContent[book->indexrow][4], "%s-%s.txt", book->masterlistContent[book->indexrow][0], book->masterlistContent[book->indexrow][1]);
				rename(book->filename, book->masterlistContent[book->indexrow][4]);
			}
		
		//write the new masterlist content
			for(int index = 0; index < book->rows; index++){
				book->masterlistContent[index][5][strcspn(book->masterlistContent[index][5], "\n")]= '\0';
				if(mark == 1){		// if the delete the particular book
					if(book->indexrow == index)
						continue;
				}
				fprintf(book->file, "%s`%s`%s`%s`%s`%s\n", book->masterlistContent[index][0], book->masterlistContent[index][1], book->masterlistContent[index][2], book->masterlistContent[index][3], book->masterlistContent[index][4], book->masterlistContent[index][5]);
			}
		
		fclose(book->file);
	}



/*********************************************************
* ---------------> RECORD MASTERLIST <--------------------
*
*	FUNCTION:
*		Record the new details in the masterlist
*
* @paramm Struct BOOK pointer	- book
**********************************************************/
	void recordMasterlist(BOOK* book){
		book->file = fopen(MASTERLIST, "a");	//open masterlist file in append mode
		
		fprintf(book->file, "%s`%s`%s`%s`%s`%s\n", book->title, book->author, book->publication_year, book->price, book->filename, book->renameMark);
		
		fclose(book->file);
	}

/*********************************************************
* ----------------> FILE to ARRAY <----------------------
*
*	FUNCTION:
*		Convert file to array
*
* @paramm struct BOOK pointer	- book
**********************************************************/
	void file_array(BOOK* book){
		book->file = fopen(MASTERLIST, "r");		//open masterlist in read mode
		
		int index = 0;
		book->rows = 0;
		
		//assigning each index of the array with the value from the file
			while(fgets(book->holdValMasterlist, 50, book->file) != NULL){
				book->token = strtok(book->holdValMasterlist, "`");
				
				while(book->token != NULL && index < 6){
					strcpy(book->masterlistContent[book->rows][index], book->token);
					book->token = strtok(NULL, "`");
					index++;
				}
					
				book->rows++;
				index = 0;
			}
			
		fclose(book->file);	
	}



/*********************************************************
* --------------------> isExist <------------------------
*
*	FUNCTION:
*		check if the file exist or not
*	if it does:
*		assign all the book details in a variable
*			and return integer value 1
*
* @paramm struct BOOK pointer 	- book
**********************************************************/
	int isExist(BOOK* book){
	file_array(book);
	strlwr(book->title);
	strlwr(book->author);
	
	for(int index = 0; index < book->rows; index++){
		if(strcmp(book->title, book->masterlistContent[index][0]) == 0 && strcmp(book->author, book->masterlistContent[index][1]) == 0){
			strcpy(book->title, book->masterlistContent[index][0]);
			strcpy(book->author, book->masterlistContent[index][1]);
			strcpy(book->publication_year, book->masterlistContent[index][2]);
			strcpy(book->price, book->masterlistContent[index][3]);
			strcpy(book->filename, book->masterlistContent[index][4]);
			strcpy(book->renameMark, book->masterlistContent[index][5]);
			printf("%s", book->masterlistContent[index][0]);
			book->indexrow = index;
			system("cls");
			return 1;
		 }
	}
	return 0;
	}



/*********************************************************
* --------------------> isEMPTY <------------------------
*
*	FUNCTION:
*		check the file if empty or not
*
* @paramm struct BOOK pointer	- book
**********************************************************/
	int isEmpty(BOOK* book){
		book->file = fopen(book->filename, "r");
		
		  fseek(book->file, 0, SEEK_END); // Move the file pointer to the end of the file
		  if(ftell(book->file) == 0) {    // Check the current position of the file pointer
		      fclose(book->file);         // Close the file
		      return 1;             	  // Return 1 if file is empty
		  }
		  fclose(book->file);             // Close the file
		  return 0;                 	  // Return 0 if file is not empty
		}



/*********************************************************
* --------------------> FILEOPEN <------------------------
*
*	FUNCTION:
*		Open file in given mode
* 
* @paramm struct BOOK pointer	- book
* @paramm constant character pointer 	- mode	- hold the value for mode
**********************************************************/
	void fileopen(BOOK* book, const char* mode){
		book->file = fopen(book->filename, mode);	//open file in given mode
		
		if(book->file == NULL)
			printf("Unable to Open File");
	}



//******************************************** USER INPUT ********************************************************

/*********************************************************
* -----------------> TITLE & AUTHOR <---------------------
*
*	FUNCTION:
*		Ask for the Book's title and author at the same 
*				time validate it
*
* @paramm Struct Book pointer	- book
*
**********************************************************/
	int TitleAndAuthor(BOOK* book){
		
		if(askTitleValidate(book, 1))
			return 1;
			
		if(askAuthorValidate(book, 1))
			return 1;
		
		snprintf(book->filename, 40, "%s-%s.txt", book->title, book->author);
		return 0;	
	}



/*********************************************************
* --------------------> ASK TITLE <------------------------
*
*	FUNCTION:
* 		Ask for title and validate it
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
**********************************************************/
	int askTitleValidate(BOOK* book, int mark){
		
		printf("\nEnter title of the book [20 max characters]:\n");
		printf("===> ");
		fgets(book->title, MAX_CHAR, stdin);
		book->title[strcspn(book->title, "\n")] = '\0';
		
		//call addbook function if true
			if(validate(book, 1)){
				if(mark == 1)
					addBook();
				else{
					system("cls");
					banner("Update Title");
					noteText(1);
					printf("\nPrevious Title \"%s\"\n\n", printText.title);
					askTitleValidate(book, 2);
				}
			}
			
		//clear the screen and return 1 if the codition is true
			if(strcmp(book->title, "0") == 0 || strcmp(book->title, " ") == 0){
				system("cls");
				return 1;
			}
		
		return 0;
	}



/*********************************************************
* --------------------> ASK AUTHOR <------------------------
*
*	FUNCTION:
* 		Ask for author and validate it
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
**********************************************************/
	int askAuthorValidate(BOOK* book, int mark){
		
		printf("\nEnter author of the book: [20 max characters]:\n");
		printf("===> ");
		fgets(book->author, MAX_CHAR, stdin);
		book->author[strcspn(book->author, "\n")] = '\0';
		
		//clear the screen and then display the banner and the note text as well as the previous title entered
			if(validate(book, 2)){
				if(mark == 1){
					printPreviousInput(book, 1);
					askAuthorValidate(book, 1);	
				}
				else{
					system("cls");
					banner("Update Author");
					noteText(1);
					printf("\nPrevious Author \"%s\"\n\n", printText.author);
					askAuthorValidate(book, 2);
				}
			}
		
		//clear the screen and return 1 if the codition is true
			if(strcmp(book->author, "0") == 0 || strcmp(book->author, " ") == 0){
				system("cls");
				return 1;
			}
		
		return 0;
	}



/*********************************************************
* -------------> ASK PUBLICATION YEAR <-------------------
*
*	FUNCTION:
* 		Ask for publication year and validate it
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
**********************************************************/
	int askPubYearValidate(BOOK* book, int mark){
		
		fflush(stdin);
		printf("\nEnter publication year [must not exceed the current date]:\n");
		printf("===> ");
		fgets(book->publication_year, 6, stdin);
		book->publication_year[strcspn(book->publication_year, "\n")] = '\0';
		
		//clear the screen and return 1 if the codition is true
			if(strcmp(book->publication_year, "0") == 0 || strcmp(book->publication_year, " ") == 0){
				system("cls");
				return 1;
			}	
			
		//clear the screen and then display the banner and the note text as well as the previous title entered
			if(validate(book, 3)){
				if(mark == 1){
					printPreviousInput(book, 2);
					askPubYearValidate(book, 1);
				}
				else{
					system("cls");
					banner("Update Publication Year");
					noteText(1);
					printf("\nPrevious Publication Year \"%s\"\n\n", printText.publication_year);
					askPubYearValidate(book, 2);
				}
			}
		
		return 0;
	}
	


/*********************************************************
* --------------------> ASK PRICE <-----------------------
*
*	FUNCTION:
* 		Ask for price and validate it
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
**********************************************************/
	int askPriceValidate(BOOK* book, int mark){
		
		printf("\nEnter price of the book [must be numbers]:\n");
		printf("===> ");
		fgets(book->price, MAX_CHAR, stdin);
		book->price[strcspn(book->price, "\n")] = '\0';
		fflush(stdin);
		
		//clear the screen and return 1 if the codition is true
			if(strcmp(book->price, "0") == 0 || strcmp(book->price, " ") == 0){
				system("cls");
				return 1;
			}
			
		//clear the screen and then display the banner and the note text as well as the previous title entered
			if(validate(book, 4)){
				if(mark == 1){
					printPreviousInput(book, 3);
					askPriceValidate(book, 1);
				}
				else{
					system("cls");
					banner("Update Price");
					noteText(1);
					printf("\nPrevious Price \"%s\"\n\n", printText.price);
					askPriceValidate(book, 2);
				}
			}
		return 0;
	}
	


/*********************************************************
* --------------------> ADD CONTENT <------------------------
*
*	FUNCTION:
*		Ask for content
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
**********************************************************/
	void addContent(BOOK* book, int mark){
		printf("Enter 0 to go back\n\n");
		printf("Enter Number of Paragraph you like to add: ");
		scanf("%d", &num);
		fflush(stdin);
		
		if(num == 0){
			system("cls");
			return;	
		}
		system("cls");
		printf("##################################################\n");
		noteText(4);
		int phar = 1;
		
		while(num != 0){
			printf("\n\n                PARAGRAPH %d\n\n", phar);
			printf("\nEnter Content (Maximum of 1000 characters):\n\n\t");
		
		//dysnamically allocate memory
			book->content = (char*) malloc(1000);
			fgets(book->content, 1000, stdin);
			book->content[strcspn(book->content, "\n")] = '\0';
			fflush(stdin);
			
			if(strcmp(book->content, "0") == 0 || strcmp(book->content, " ") == 0 || strlen(book->content) < 1){
				if(mark == 1){
					system("cls");
					remove(book->filename);
					main();
				}
				else
					return;
			}
			
			fileopen(book, "a");
			fprintf(book->file, "%s\n", book->content);
			
			free(book->content);
			fclose(book->file);
			num--;
			phar++;
			printf("\n\n");
		}
		if(mark == 2){
			system("cls");
			banner("ADDED SUCCESSFULLY");
			main();
		}
		system("cls");
		recordMasterlist(book);
		main();
	}



//******************************************** AESTHETIC ********************************************************

/*********************************************************
* --------------------> PREV INPUT <------------------------
*
*	FUNCTION:
*		Display previous input 
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
**********************************************************/
	void printPreviousInput(BOOK* book, int mark){
		system("cls");
		banner("ADD BOOK");
		noteText(1);
		if(mark == 1 || mark == 2 || mark == 3 || mark == 4 ){
			printf("\nEnter title of the book [20 max characters]:\n");
			printf("===> %s\n", book->title);
			
			if(mark == 2 || mark == 3 || mark == 4 ){
				printf("\nEnter author of the book [20 max characters]:\n");
				printf("===> %s\n", book->author);
				
				if(mark == 3 || mark == 4 ){
					printf("\nEnter publication year of the book [4 max characters]:\n");
					printf("===> %s\n", book->publication_year);
					
					if(mark == 4 ){
						printf("\nEnter title of the book [must be numbers]:\n");
						printf("===> %s\n", book->price);
					}
				}
			}
		}
	}



/*********************************************************
* --------------------> VALIDATE <------------------------
*
*	FUNCTION:
*		Validate the user input
*
* @paramm Struct Book pointer 	- book
* @paramm integer				- mark		- serves as marking
*
* @return 1
*	if the length of the inputed value is less than 1
*	else return 0
**********************************************************/
	int validate(BOOK* book, int mark){
		int lenTitle, lenAuthor, lenYear, lenPrice, count = 0;
		
		fflush(stdin);
		lenTitle = strlen(book->title);				//length of the title
		lenAuthor = strlen(book->author);			//length of the author
		lenYear = strlen(book->publication_year);	//length of the publication year
		lenPrice = strlen(book->price);				//Length of the price
	
		//display a notice that last 2 second then clear the screen and return 1
			if(mark == 1){
				if(lenTitle < 1){
					printf("\n\t\tPlease Enter Title");
					goto return1;
				}
				else if(lenTitle > 20){
					printf("\n\tTitle must not exceed 20 characters");
					goto return1;
				}
			}
		
		//display a notice that last 2 second then clear the screen and return 1
			if(mark == 2){
				if(lenAuthor < 1){
					printf("\n\t\tPlease Enter Author");
					goto return1;
				}
				else if(lenAuthor > 20){
					printf("\n\tAuthor must not exceed 20 characters");
					goto return1;
				}
			}
		
		//display a notice that last 2 second then clear the screen and return 1
			if(mark == 3){
				for(int index = 0; index < lenYear; index++){
					if(isdigit(book->publication_year[index]))
						count++;
				}
				int numYear = atoi(book->publication_year);
				
				if(lenYear < 1){
					printf("\n\t       Please Enter Publication Year");
					goto return1;
				}
				else if(lenYear != 4){
					printf("\n   Please input the correct format for year(1999)!!!");
					goto return1;
				}
				
				if(numYear > 2023){
					printf("\n    Year must exceed the current date!!!");
					goto return1;
				}
				if(count != 4){
					printf("\n\tPlease enter number[1-9]");
					goto return1;
				}
			}
		
		//display a notice that last 2 second then clear the screen and return 1
			if(mark == 4){
				for(int index = 0; index < lenPrice; index++){
					if(isdigit(book->price[index]))
						count++;
					if(book->price[index] == '.')
						count++;
				}
				
				if(lenPrice  < 1){
					printf("\n\t\tPlease Enter Price");
					goto return1;
				}
				if(count != lenPrice){
					printf("\n\tPlease enter number[1-9]");
					goto return1;
				}
			}
			
			if(mark == 5){
				for(int index = 0; index < book->rows; index++){
					if(strcmp(book->masterlistContent[book->rows][4], book->filename) == 0){
						printf("\tTry Another Filename!!!\n");
						goto return1;
					}		
				}
			}
			
		//return 0 if none of the condition is true
			return 0;
			
	return1:
		sleep(2);
		system("cls");
		return 1;
	}



/*********************************************************
* --------------> AUTO ADJUST CONTENT <-------------------
*
*	FUNCTION:
*		Display content with the mechanism to auto
*				adjust in the box
*
* @paramm 2D array	- contentStr	- hold the content value
* @paramm integer	- lentstr	- length of the contentStr
* @paramm integer	- page		- the index of what to be adjust
**********************************************************/
	void adjustContentInTheBox(char contentStr[10][1000], int lenstr, int page){		
		int uselen, numrow = 0, nuumrow = 42, tem = 0;
		
		while(1){
			if(lenstr < 1)
				break;
			uselen = lenstr - 42;
			lenstr = uselen;
			numrow++;
		}
		
		while(numrow != 0){
			printf("|   ");
			
			for(num = tem; num < nuumrow; num++){
				if(contentStr[page - 1][num] == '\n')
					break;
				printf("%c", contentStr[page - 1][num]);
			}
			if(numrow != 1)
				printf("   |\n");
			else
				printf("\n");
			numrow--;
			tem = nuumrow;
			nuumrow += 42;
		}
	}



/*********************************************************
* --------------> AUTO ADJUST DETAILS <-------------------
*
*	FUNCTION:
*		Display detaild with the mechanism to auto
*				adjust in the box
*
* @paramm struct BOOK pointer	- book
* @paramm integer	- mark		- hold value for marking
* @paramm constant character pointer	- label		- text label
**********************************************************/
	void adjustBoxDetails(BOOK* book, int mark, const char* label){
		char temphold[20];
		if(mark == 1)
			strcpy(temphold, book->masterlistContent[book->indexrow][0]);
		else if(mark == 2)
			strcpy(temphold, book->masterlistContent[book->indexrow][1]);
		else if(mark == 3)
			strcpy(temphold, book->masterlistContent[book->indexrow][2]);
		else
			strcpy(temphold, book->masterlistContent[book->indexrow][3]);
			
		int lenstr, strtIterate;
		lenstr = strlen(temphold) + 6 + strlen(label);
		strtIterate = 50 - lenstr;
		
		printf("|     %s%s", label, temphold);
		for(int index = 0; index < strtIterate; index++){
			if(index == strtIterate - 1){
				printf("|\n");
				continue;
			}
			printf(" ");
		}
	}



/*********************************************************
* --------------------> INVALID <-------------------------
*
*	FUNCTION:
*		Display invalid warning that last for 2 second
*				and then clear the screen
*
**********************************************************/
	void invalid(){
		printf("\n\tInvalid Choice!!!\n\tPlease Try Again\n");
		sleep(2);
		system("cls");
	}



/*********************************************************
* ---------------------> MENU <---------------------------
*
*	FUNCTION:
*		Display the Menu Option and take input from user
*				and then clear the screen
*
* @paramm Structure BOOK pointer	- book
*
**********************************************************/
	void menu(BOOK* book){
		printf("|----->                                    <-----|\n");
		printf("|---->           [1] Add Book               <----|\n");
		printf("|--->            [2] Read Book               <---|\n");
		printf("|-->             [3] Book Details             <--|\n");
		printf("|->              [4] Update Book               <-|\n");
		printf("|->              [5] Delete Book               <-|\n");
		printf("|-->             [6] Rename Book              <--|\n");
		printf("|--->            [7] Booklist                <---|\n");
		printf("|---->           [8] Exit                   <----|\n");
		printf("|----->                                    <-----|\n");
		printf("##################################################\n");
		
		printf("Enter Choice [1-8]: ");
		book->choice = getchar();
		fflush(stdin);
		system("cls");
	}



/**************************************************************************
* -----------------------------> BANNER <----------------------------------
*	
*	FUNCTION:
*		Display the header design with the mechanism to auto adjust 
*			and place the pass string value in the middle
*				  without destroying the design
*	
* @paramm constant array of char	- headerName	- Hold a string value
*
***************************************************************************/
	void banner(const char* headerName){
		int lenName, lenChar, totalLen;										//declaration
		lenName = strlen(headerName);										//length of the string
		totalLen = 50 - lenName - 2;										//Number of times the loop iterate
		lenChar = (50 - lenName) / 2;										//number of char to start printing the string
		
		printf("##################################################\n");
		
	//loop depends to the value of totalLen and print '#'
		for(int index = 0; index < totalLen ; index++){
			
		//if true	- start printing the string
		//else		- continue printing "#"
			if(index == lenChar - 1){
				printf(" ");
				
				for(int len = 0; len < lenName; len++){
					printf("%c", headerName[len]);
				}
				
				printf(" ");
			}
			
		//add newline to the last character
			if(index == totalLen - 1)
				printf("#\n");
			
			printf("#");	
		}
		
		printf("#################################################\n");
	}



/*********************************************************
* ------------------> NOTICE TEXT <-----------------------
*
*	FUNCTION:
*		Display notice in the console
**********************************************************/
	void noteText(int mark){
		if(mark == 1){
			printf("|                                                |\n");
			printf("|   ****************************************     |\n");
			printf("|   *  NOTE:                               *     |\n");
			printf("|   *    Enter \"0\" or press \"SPACE BAR\"    *     |\n");
			printf("|   *     with no content to GO BACK       *     |\n");
			printf("|   ****************************************     |\n");
			printf("|________________________________________________|\n");
		}
		else if(mark == 2){
			printf("|  NOTE: Press Any Keys to Stop Reading          |\n");
			printf("|         (Except for back or next value)        |\n");
			printf("|           \"ENTER\" means exit                   |\n");
			printf("|                                                |\n");
			printf("##################################################\n");
			printf("|                                                |\n");
		}
		else if(mark == 3){
			printf("|  NOTE: Press Any Keys to GO BACK               |\n");
			printf("|                                                |\n");
			printf("##################################################\n");
		}
		else if(mark == 4){
			printf("|                                                |\n");
			printf("|   ****************************************     |\n");
			printf("|   *  NOTE:                               *     |\n");
			printf("|   *    Enter \"0\" or press \"SPACE BAR\"    *     |\n");
			printf("|   *    or press \"ENTER\" with no content  *     |\n");
			printf("|   *           to go to MENU              *     |\n");
			printf("|   ****************************************     |\n");
			printf("|________________________________________________|\n");
		}
	}









