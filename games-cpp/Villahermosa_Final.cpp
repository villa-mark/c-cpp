#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <fstream>
using namespace std;

//Functions for Shortcut Newline, Tab, and Design
void design(int a, int b, int c); 	//Use to add 50 asterisk in a line
void tab(int a); 					//Use to add Tab
void line(int a); 					//Use to add NewLine
void color(int a);					//Used to add Color
void side(int a, int b);			//Used to add 2 asterisk
//Functions for Display
void menu(char *choice);			//Main Menu of the Game
void about(char *choice);
void help(char *choice);
void hellp(int *endless);
void play(char *choice);
//Functions for Logic, and Mechanism
void player();
void computer(int endless);
void heart(int *countMistake);
void mistakeBox(char *mistakeEmpty, int *mark);
void box(int *countword, char *storeword);
bool checkWinner(int *countword, char *storeword);
void difficulty(char *difficulty);
void allign(int *countMean, const char* meanchar);


//MAIN function
int main(){
	//Variable Declaration
	char choice;
	//START 
	loop:
	system("cls");
	menu(&choice);
	if(choice == '1' || choice == '2' || choice == '3' || choice == '4'){
		system("cls");
	}
	switch(choice){
		//PLAY
		case '1':{
			loop1:
			system("cls");
			play(&choice);
			if(choice == '1' || choice == '2' || choice == '3' || choice == '4'){
			system("cls");
			}
			switch(choice){
				//PLAYER
				case '1':{
					playAgain:
					system("cls");
					player();
					side(34, 2); color(36); tab(2); color(32); cout<<"[T]TRY AGAIN"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); 
					line(1); side(34, 2); color(36); tab(2); color(32); cout<< "[B]GO BACK"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); 
					line(1); side(34, 2); color(36); tab(2); color(32); cout<<"[Q]QUIT"; color(0); side(34, 4); line(1); side(34, 2); side(34, 6); line(1);
					side(34, 2); side(34, 6); line(1);
			   		side(34, 2); side(34, 6); line(1); design(34, 2, 1); design(34, 2, 1);
					again: choice=getch(); choice = toupper(choice); side(34, 4); 
					switch(choice){
						case 'T':{
							goto playAgain;
						}
						case 'B':{
							goto loop1;
						}
						case 'Q':{
							system("cls");
							line(3); tab(4);color(33); cout<< "THANK YOU FOR PLAYING"; color(0); sleep(3);
							return 0;
						}
						default:{
							color(31); cout << " Invalid Input!!!"; color(0);
							goto again; 
						}
					}
					break;
				}
				//COMPUTER
				case '2':{
					playAgain1:
					computer(0);
					side(34, 2); color(36); tab(2); color(32); cout<<"[T]TRY AGAIN"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); 
					line(1); side(34, 2); color(36); tab(2); color(32); cout<< "[B]GO BACK"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); 
					line(1); side(34, 2); color(36); tab(2); color(32); cout<<"[Q]QUIT"; color(0); side(34, 4); line(1); side(34, 2); side(34, 6); line(1);
					side(34, 2); side(34, 6); line(1);
			   		side(34, 2); side(34, 6); line(1); design(34, 2, 1); design(34, 2, 1);
					again1: choice=getch(); choice = toupper(choice); side(34, 4); 
					switch(choice){
						case 'T':{
							goto playAgain1;
						}
						case 'B':{
							goto loop1;
						}
						case 'Q':{
							system("cls");
							line(3); tab(4);color(33); cout<< "THANK YOU FOR PLAYING"; color(0); sleep(3);
							return 0;
						}
						default:{
							color(31); cout << " Invalid Input!!!"; color(0);
							goto again1; 
						}
					}
					break;
				}
				//ENDLESS
				case '3':{
					playAgain2: system("cls");
					computer(1);
					side(34, 2); color(36); tab(2); color(32); cout<<"[T]TRY AGAIN"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); 
					line(1); side(34, 2); color(36); tab(2); color(32); cout<< "[B]GO BACK"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); 
					line(1); side(34, 2); color(36); tab(2); color(32); cout<<"[Q]QUIT"; color(0); side(34, 4); line(1); side(34, 2); side(34, 6); line(1);
					side(34, 2); side(34, 6); line(1);
			   		side(34, 2); side(34, 6); line(1); design(34, 2, 1); design(34, 2, 1);
					again2: choice=getch(); choice = toupper(choice); side(34, 4); 
					switch(choice){
						case 'T':{
							goto playAgain2;
						}
						case 'B':{
							goto loop1;
						}
						case 'Q':{
							system("cls");
							line(3); tab(4);color(33); cout<< "THANK YOU FOR PLAYING"; color(0); sleep(3);
							return 0;
						}
						default:{
							color(31); cout << " Invalid Input!!!"; color(0);
							goto again2; 
						}
		
					break;
				}}
				//BACK
				case '4':{
					goto loop;
					break;
				}
				default:{
					color(31); cout << " Invalid Input!!!"; color(0); 
					cout << "\n\t\tPLEASE CHOOSE FROM [1/4]"; 
					sleep(1);
					system("cls");
					goto loop1; 
				}
			break;
			}}
		//HELP
		case '2':{
			help(&choice);
			goto loop;
			break;
		}
		//ABOUT
		case '3':{
			about(&choice);
			goto loop;
			break;
		}
		//QUIT
		case '4':{
			color(33); cout << "\n\n\n\t\t\tTHANK YOU FOR PLAYING!!!"; color(0); sleep(3);
			return 0;
		}
		default:{
			tab(2); color(31); cout << " Invalid Input!!!\n"; color(0); 
			tab(2); cout << "\t    PLEASE CHOOSE FROM [1/4]"; 
			sleep(1);
			goto loop; 
		}
	}
	
	return 0;
	}

void computer(int endless){

	srand(time(NULL));
    
    char storeword[]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char mistakeEmpty[]={' ', ' ', ' ', ' ', ' '};
	string words[] = {"ENGINEER", "DIPLOMA", "PROGRAMMING",
                  "PROBLEM", "COMPUTER", "UNIVERSITY",
                  "WORLD", "NETWORK", "PHYSICAL",
                  "LAYER", "DATA", "HUMAN", "SECRET",
                  "PILLOW", "BUCKET", "JOB", "TUMBLER",
                  "MONDAY", "SUNDAY", "TABLE", "UNIFORM",
                  "TEAPOT", "SOCKET", "LOVE"};
	string meaning[] = {"A person who designs, builds, or maintains engines, machines, or public works",
                 "A certificate awarded by an educational establishment to show that someone has successfully completed a course of study", 
                 "The action or process of writing computer program", 
                 "A matter or situation regarded as unwelcome or harmful and needing to be dealt with and overcome",     
                 "An electronic device for storing and processing data", 
                 "An educational institution assigned for instruction, examination, or both, of students in many branches of advanced learning, conferring degrees in various faculties",      
                 "The earth, together with all of its countries people, and natural features", 
                 "Connecting to or interacting", 
                 "Relating to the body as opposed to the mind::tangible or concrete",  
                 "A sheet, quality, or thickness of material", 
                 "Facts and statistics collected together for reference or analysis", 
                 "A living being", 
                 "not known or seen or not meant to be known or seen by others",
                 "A rectangular cloth bag stuffed with feathers, foam rubber, or other sort materials, used to support the head", 
                 "A roughly cylindrical open container, typically made of metal or plastic", 
                 "An act of prodding, trusting, or wrenching a paid position of regular employment", 
                 "A drinking glass with straight sides and no handle or stem", 
                 "A day named after the moon", 
                 "A day named after the sun", 
                 "A piece of furniture with a flat top and one or more legs", 
                 "Remaining the same in all cases and at all times", 
                 "A pot with a handle, spout, and lid, in which tea is brewed and from which it is poured", 
                 "A natural or artificial hollow into which something fits or in which something revolves", 
                 "Feel a deep romantic or sexual attachment to someone"};
    char level; int x=0;             
    loop2:
    int score=0;
    system("cls");
    difficulty(&level);
    level = toupper(level);
    if(level=='1'){
    	x=1;
	}
	else if(level=='2'){
		x=0;
	}
	else if(level=='2'){
		cout << "HIGH SCORE:\n\n";
		ofstream FILE("record.txt");
		FILE << score;
		FILE.close();
	}
	else if(level=='/'){
		system("cls"); hellp(&endless); goto loop2;
	}
	else{
	system("cls"); 
	line(4); tab(4); color(31); cout << " Invalid Input!!!"; color(0); 
	line(1); tab(4); cout << "PLEASE ENTER [1/2]"; 
	sleep(1);
	goto loop2;
    }
	int run=1, flag=0, mark=0, v=0, fin=1, randomNumber; 
	int countMistake=5; char finite[]={'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	randomNumber = rand()%24;
	int countword = words[randomNumber].length();
    int countMean = meaning[randomNumber].length();
    const char* meanchar = meaning[randomNumber].c_str();
	const char* wordchar = words[randomNumber].c_str();
	
	system("cls");
	endlessloop:
	char letter;
	if(endless==1){
	while(true){
		randomNumber = rand()%24;
		if(finite[randomNumber]==' '){
			countword = words[randomNumber].length();
   		 	countMean = meaning[randomNumber].length();
    		meanchar = meaning[randomNumber].c_str();
			wordchar = words[randomNumber].c_str(); break;
		}}}
    
	
	while(run!=0){
		system("cls");
		design(34, 2, 1); 
		tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
		design(34, 2, 1); line(1);
		tab(2); color(32); cout<<"Mistakes Are Store In This Box"; color(0); tab(2);color(33); cout<<"LIFE: "; color(0); heart(&countMistake); line(1);
		mistakeBox(mistakeEmpty, &mark); tab(2);
		tab(1); color(32); cout<< "   Guess This " << countword << " Letter Word:"; color(0); line(1);
		if(x==1){
			allign(&countMean, meanchar);
		}
		box(&countword, storeword); 
		design(34, 2, 2);
		letter=getch(); letter=toupper(letter);
		//logic and mechanism
		int i, track=0;
		for(i=0; i<countword; i++){
		if(letter==wordchar[i]){
			storeword[i]=letter;}	
		if(letter!=wordchar[i]){
			track++;
		}}
		if(track==countword){
			mistakeEmpty[v]=letter; v++; countMistake--;
		}
		track=0;	
		if(checkWinner(&countword, storeword)==true){
			if(endless==0){
				run=0;
			}
			else if(endless==1){
			score++;
			system("cls");
			design(34, 2, 1); 
			tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
			design(34, 2, 1); line(1);
			tab(2); color(32); cout<<"Mistakes Are Store In This Box"; color(0); tab(2);color(33); cout<<"LIFE: "; color(0); heart(&countMistake); line(1);
			mistakeBox(mistakeEmpty, &mark); tab(2);
			tab(1); color(32); cout<< "   Guess This " << countword << " Letter Word:"; color(0); line(1);
			if(x==1){
			allign(&countMean, meanchar);
			}
			box(&countword, storeword); 
			tab(4); cout<< "   CORRECT";
			line(1); tab(4); cout << "   SCORE: "; cout << score; 
			line(3); tab(4); cout<< "   ENTER\n"; char ok;
			design(34, 2, 2);
			ok=getch();
			for(i=0; i<countword; i++){
			storeword[i]=' ';}
			
			system("cls");
			design(34, 2, 1); 
			tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
			design(34, 2, 1); line(1);
			tab(2); color(32); cout<<"Mistakes Are Store In This Box"; color(0); tab(2);color(33); cout<<"LIFE: "; color(0); heart(&countMistake); line(1);
			mistakeBox(mistakeEmpty, &mark); tab(2);
			tab(1); color(32); cout<< "   Guess This " << countword << " Letter Word:"; color(0); line(1);
			if(x==1){
				allign(&countMean, meanchar);
			}
			box(&countword, storeword); 
			finite[fin]='o'; fin++;
		
			goto endlessloop;
			}
		
		}
		if(countMistake==0){
			run=0;
		}
	}
	if(countMistake==0){
	system("cls");
	if(endless==0){
	design(34, 2, 1); 
	tab(2); cout<< "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1); line(3);
	tab(2); color(31); cout<< "*******************\033[5m YOU LOSE \033[0m\033[31m*********************"; color(0); line(2);
	tab(2); color(33); cout<< "The word is: "; color(4); cout<< words[randomNumber]; line(2); color(0);
	allign(&countMean, meanchar); line(5);}
	else if(endless==1){
	design(34, 2, 1); 
	tab(2); cout<< "\033[1;34m****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1); line(3);
	tab(2); color(31); cout<< "*******************\033[5m GAME OVER \033[0m\033[31m********************"; color(0); line(2); color(0);
	tab(2); color(33); cout<< "The word is: "; color(4); cout<< words[randomNumber]; line(1); color(0);
	tab(2); color(33); cout<< "SCORE: "; cout<< score; line(2); color(0);
	allign(&countMean, meanchar); line(5);
	}
	}
	if(checkWinner(&countword, storeword)==true){
	system("cls");
	design(34, 2, 1); 
	tab(2); cout<< "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1); line(3);
	tab(2); color(33); cout<< "*******************\033[5m YOU WIN \033[0m\033[33m**********************"; color(0); line(2);
	tab(2); color(33); cout<< "The word is: "; color(4); cout<< words[randomNumber]; line(2); color(0);
	allign(&countMean, meanchar); line(5);
	}
	char choice1;
	tab(4); cout<< "   PRESS ENTER\n"; 
	design(34, 2, 2); choice1=getch(); system("cls");
	design(34, 2, 1);
	tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1);
	if(countMistake==0){
		if(endless==0){
		side(34, 2); side(34, 6); line(1);
		side(34, 2); side(34, 6); line(1);
		side(34, 2); color(36); tab(2); color(31); cout<< "  YOU LOSE"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); line(1);}
		else if(endless==1){
		side(34, 2); side(34, 6); line(1);
		side(34, 2); side(34, 6); line(1);
		side(34, 2); color(36); tab(2); color(31); cout<< " GAME OVER"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); line(1);
		}
	}
	if(checkWinner(&countword, storeword)==true){
		side(34, 2); side(34, 6); line(1);
		side(34, 2); side(34, 6); line(1);
		side(34, 2); color(36); tab(2); color(33); cout<< "  YOU WIN"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); line(1);
	}
}
void allign(int *countMean, const char* meanchar){
	int i;
	tab(2);color(35); cout<< "Difinition: "; color(0); line(1); tab(2); cout<< "-> "; color(33); 
	for(i=0; i<*countMean; i++){
		cout<< meanchar[i];
		if(i==46||i==96||i==144){
			cout<<"\n\t\t";
		}
	}
	color(0); line(2);
}
void difficulty(char *level){
	
    design(34, 2, 1);
	tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1);
	side(34, 2); tab(5); color(32); cout<<"[?]HELP "; side(34, 0); line(1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); color(36); cout << "\t\t  DIFFICULTY"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[1] EASY"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[2] HARD"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[3] HIGH SCORE"; side(34, 3); line(1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); side(34, 6); line(1);
	design(34, 2, 2);
	line(2);
	tab(2); *level = getch();
}
void player(){
	string word, difinition;
	char choice, letter;
	char storeword[]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char mistakeEmpty[]={' ', ' ', ' ', ' ', ' '};
	int x=0;
	design(34, 2, 1);
	tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1); line(1);
	
	tab(2); color(33); cout<<"Enter Word To Be Guess:"; color(0); line(2); tab(2); cout<< "-> "; cin>> word;
	int countword = word.length();
	const char* wordchar = word.c_str();
	loop:
	line(4); tab(2); color(33); cout<< "Want To Add Difinition?[Y/N]: "; color(0);
	choice = getch(); choice=toupper(choice); system("cls");
	if(choice=='Y'){
		design(34, 2, 1);
		tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
		design(34, 2, 1); line(1);
		tab(2); color(32); cout<< "WORD: "; color(0); color(33); cout << word; line(1); color(0);
		tab(2); color(35); cout<< "Enter Difinition: "; color(0); getline(cin, difinition); getline(cin, difinition);
		x=1;
	}
	else if(choice=='N'){
		x=0;
	}
	else{
		color(31); line(3);  tab(2); cout << " Invalid Input!!!"; color(0); line(1);
		tab(2); cout << "PLEASE CHOOSE [Y/N]"; 
		sleep(1);
		goto loop;
	}
	int run=1, countMistake=5, mark=0, flag=0, v=0;
	while(run!=0){
		system("cls");
		design(34, 2, 1); 
		tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
		design(34, 2, 1); line(1);
		tab(2); color(32); cout<<"Mistakes Are Store In This Box"; color(0); tab(2);color(33); cout<<"LIFE: "; color(0); heart(&countMistake); line(1);
		mistakeBox(mistakeEmpty, &mark); tab(2);
		tab(1); color(32); cout<< "   Guess This " << countword << " Letter Word:"; color(0); line(1);
		if(x==1){
			tab(2);color(35); cout<< "Difinition: "; color(0); line(1); tab(2); cout<< "-> "; color(33); cout<< difinition; color(0); line(2);
		}
		box(&countword, storeword); letter=getch();
		//logic and mechanism
		int i, track=0;
		for(i=0; i<countword; i++){
		if(letter==wordchar[i]){
			storeword[i]=letter;}	
		if(letter!=wordchar[i]){
			track++;
		}}
		if(track==countword){
			mistakeEmpty[v]=letter; v++; countMistake--;
		}
		track=0;	
		if(checkWinner(&countword, storeword)==true){
			run=0;
		}
		if(countMistake==0){
			run=0;
		}
		}
		system("cls");
		design(34, 2, 1);
		tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
		design(34, 2, 1); line(1);
		tab(2); color(32); cout<<"Mistakes Are Store In This Box"; color(0); tab(2); color(33); cout<<"LIFE: "; color(0); heart(&countMistake); line(1);
		mistakeBox(mistakeEmpty, &mark); tab(2);
		tab(1); color(32); cout<< "   Guess This " << countword << " Letter Word:"; color(32); line(1);
		if(x==1){
			tab(2);color(35); cout<< "Difinition: "; color(0); line(1); tab(2); cout<< "-> "; color(33); cout<< difinition; color(0); line(2);
		}
		char choice1;
		box(&countword, storeword); line(1); tab(2); 
		if(countMistake==0){
			color(33); cout<< "The word is: "; color(4); cout<< word; line(2); color(0); tab(2);
			tab(2); color(31); cout<< "  YOU LOSE"; color(0); line(2);
		}
		if(checkWinner(&countword, storeword)==true){
			tab(2); color(33); cout<< "  YOU WIN"; color(0); line(2);
		}
		tab(4); cout<< "PRESS ENTER"; choice1=getch(); system("cls");
		design(34, 2, 1);
		tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
		design(34, 2, 1);
		if(countMistake==0){
			side(34, 2); side(34, 6); line(1);
			side(34, 2); side(34, 6); line(1);
			side(34, 2); color(36); tab(2); color(31); cout<< "  YOU LOSE"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); line(1);
		}
		if(checkWinner(&countword, storeword)==true){
			side(34, 2); side(34, 6); line(1);
			side(34, 2); side(34, 6); line(1);
			side(34, 2); color(36); tab(2); color(33); cout<< "  YOU WIN"; color(0); side(34, 3); line(1); side(34, 2); side(34, 6); line(1);
		}
}

bool checkWinner(int *countword, char *storeword){
	int i;
	for(i=0; i<*countword; i++){
		if(storeword[i]==' '){
			return false;
		}		
	}
	for(i=0; i<*countword; i++){
		if(storeword[*countword]!=' '){
			return true;
		}}		

}
void box(int *countword, char *storeword){
	int i;
	tab(2);
	for(i=1; i<=*countword; i++){
		color(34); cout<< "____"; color(0);}
		color(34); cout<< "_\n"; color(0);
	tab(2);
	for(i=0; i<*countword; i++){
		color(34); cout<< "| "; color(33); cout<< storeword[i]; color(0); color(34); cout<< " "; color(0);}
		color(34); cout<< "|\n";  color(0);
	tab(2);
	for(i=1; i<=*countword; i++){
		color(34); cout<< "|___"; color(0);}
		color(34); cout<< "|\n";  color(0);
		line(2);
}
void mistakeBox(char *mistakeEmpty, int *mark){
	int i;
	
	tab(2);
	for(i=1; i<=5; i++){
		color(31); cout<< "____"; color(0);}
		color(31); cout<< "_\n"; color(0);
	tab(2);
	for(i=0; i<5; i++){
		color(31); cout<< "| ";  color(0);  color(32); cout<< mistakeEmpty[i]; color(0); cout<< " ";}
		color(31); cout<< "|\n"; color(0);
	tab(2);
	for(i=1; i<=5; i++){
		color(31); cout<< "|___"; color(0);}
		color(31); cout<< "|\n"; color(0);
		line(2);
}
void heart(int *countMistake){
	int i;
	for(i=0; i<*countMistake; i++){
		color(31); cout<< "@"; color(0);
	}
}


//Functions Fisrt Display
void play(char *choice){
	design(34, 2, 1);
	tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); color(36); cout << "\t\t[1] Player"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[2] Computer"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[3] Endless"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[4] Go Back"; side(34, 3); line(1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); side(34, 6); line(1);
	design(34, 2, 2);
	line(2);
	tab(2); *choice = getch();
}
void hellp(int *endless){
	char choice;
	design(34, 2, 2);
	tab(5); color(37); cout << "\033[1;35m\033[1m\033[5mHELP\033[0m"; line(3);
	tab(2); color(35); cout << "How to Play this Game?\n\n"; color(0);																									
	tab(5); color(33); cout << "EASY:\033[0m"; cout<< "\033[32m\n\t\t   Easy mode has a given difinition of the word to\n\t\tbe guess making the game easy to play\n\n"; color(0);
	tab(5); color(33); cout << "HARD:\033[0m"; cout<< " \033[32m\n\t\t  Hard mode has no given difinition of the word  \n\t\tto be guess, all you need to do, is to guess the\n\t\tword with no any hint\n\n"; color(0);
	if(*endless==1){ 													   														  											
	tab(5); color(33); cout << "ENDLESS:\033[0m"; cout<< "\033[32m\n\t\t   In Endless mode, you will be given infinite words\n\t\tto be guess, as long as you have a life. \nOnce you have no life left the game will end \n\t\timmediately.\n\n"; color(0);
	}
	line(2); tab(2); color(34); tab(3); cout << "ENTER\n"; color(0); 
	design(34, 2, 2);
	choice = getch();
	system("cls");
}
void help(char *choice){
	A:
	system("cls");
	design(34, 2, 2);
	tab(5); color(37); cout << "\033[1;35m\033[1m\033[5mHELP\033[0m"; line(3);
	tab(2); color(35); cout << "How to Play this Game?\n\n"; color(0);
	tab(2); color(33); cout << "   The player must guess the word by entering any\n\t\tletter with only five mistake. Everytime you\n\t\tentered the right letter of the word, it will\n\t\tappear automatically in the board and in the\n\t\tright position.\n\n"; color(0);
	line(2); tab(2); color(34); tab(5); cout << "[>]NEXT\n"; color(0); 
	design(34, 2, 2);
	*choice = getch(); *choice = toupper(*choice);
	if(*choice == '.'){
		goto B;
	}
	else{
		color(31); line(3); tab(4);cout << "  Invalid Input!!!"; color(0); 
		cout << "\n\t\t\t\tPRESS \">\" to Next"; sleep(1);
		goto A;
	}
	B:
	system("cls");
	design(34, 2, 2);
	tab(5); color(37); cout << "\033[1;35m\033[1m\033[5mHELP\033[0m"; line(3);
	tab(2); color(35); cout << "SAMPLE\n\n"; color(0);
	tab(2); color(33); cout << "The word to be guess is \033[0m\"\033[36mPROGRAM\033[0m\"\n"; color(0);
								
	tab(2); color(33); cout << "There will be boxes corresponding to the number of\n\t\tletters of the word.\033[0m\n\n\t\tSince \033[0m\"\033[36mPROGRAM\033[0m\" has seven letters,\n\t\tthe box will look like this:\n"; color(0);
	tab(2); color(36); cout << "_____________________________\n\t\t|   |   |   |   |   |   |   |\n\t\t|___|___|___|___|___|___|___|\n\n\t\t"; color(0);
	line(2); tab(2); color(34); cout << "[<]BACK\t\t\t\t\t[>]NEXT\n"; color(0); 
	design(34, 2, 2);
	*choice = getch(); *choice = toupper(*choice);
	if(*choice == '.'){
		goto C;
	}
	else if(*choice == ','){
		goto A;
	}
	else{
		color(31); line(3); tab(4);cout << "  Invalid Input!!!"; color(0); 
		cout << "\n\t\t\tPRESS \">\" to Next and \"<\" to Back"; sleep(1);
		goto B;
	}
	C:
	system("cls");
	design(34, 2, 2);
	tab(5); color(37); cout << "\033[1;35m\033[1m\033[5mHELP\033[0m"; line(3);
	tab(2); color(33); cout << "Everytime you entered the right letter, the letter\n\t\twill automatically position in the box\n\t\tEXAMPLE:\n\t\t\033[37mEnter Letter:\033[0m\"\033[33mP\033[0m\"\n"; color(0);
	tab(2); cout << "_____________________________\n\t\t| \033[33mP\033[0m |   |   |   |   |   |   |\n\t\t|___|___|___|___|___|___|___|\n\n\t\t\033[33mUntil you fill the boxes with less than 5 mistakes\n\t\tYou win!!!\033[0m";
	line(2); tab(2); color(34); cout << "[<]BACK\t\t\t\t[>]MAIN MENU\n"; color(0); 
	design(34, 2, 2);
	*choice = getch(); *choice = toupper(*choice);
	if(*choice == '.'){
		
	}
	else if(*choice == ','){
		goto B;
	}
	else{
		color(31); line(3); tab(4);cout << "  Invalid Input!!!"; color(0); 
		cout << "\n\t\t\tPRESS \"<\" to Next and \">\" to Main Menu"; sleep(1);
		goto C;
	}
	
}
void menu(char *choice){
	design(34, 2, 1);
	tab(2); cout << "\033[1;34m*****************\033[0m \033[1;35m\033[1m\033[5mGUESS THE WORD\033[0m \033[1;34m*****************\033[0m\n";
	design(34, 2, 1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); color(36); cout << "\t\t[1] Play"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[2] Help"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[3] About"; side(34, 3); line(1);
	side(34, 2); color(36); cout << "\t\t[4] Quit"; side(34, 3); line(1);
	side(34, 2); side(34, 6); line(1);
	side(34, 2); side(34, 6); line(1);
	design(34, 2, 2);
	line(2);
	tab(2); *choice = getch();
}
void about(char *choice){
	design(34, 2, 2);
	tab(5); color(37); cout << "\033[1;35m\033[1m\033[5mABOUT\033[0m"; line(3);
	tab(2); color(33); cout << "Name: "; color(0); color(36); tab(1); cout<<" "; color(4); cout << "VILLAHERMOSA, MARK ANTHONY N."; color(0); color(0); line(1);
	tab(2); color(33); cout << "Age: "; color(0); color(36); tab(1); cout<<" "; color(4); cout << "19"; color(0); color(0); line(1);
	tab(2); color(33); cout << "Course: "; color(0); color(36); cout<<" "; color(4); cout << "Computer Engr."; color(0); color(0); line(1);
	tab(2); color(33); cout << "Section: "; color(0); color(36); color(4); cout << "2F"; color(0); color(0); line(1);
	tab(2); color(33); cout << "School: "; color(0); color(36); cout<<" "; color(4); cout << "CITE Technical Institute Inc."; color(0); color(0); line(1);
	line(1); tab(2); cout << "This is my Project in PLD (Programming Logic Design)\n";
	design(34, 2, 2);
	line(1); tab(2); color(34); cout << "Press Enter to GO Back"; color(0); *choice = getch();
}
//Decoration
void color(int a){
	cout << "\033[" << a << "m";
}
void line(int a){
	int i;
	for(i=0; i<a; i++){
		cout <<"\n";
	}
}
void design(int a, int b, int c){
	int i, j, k;
	for(k=0; k<c; k++){
		for(j=0; j<b; j++){
			cout << "\t";
			}
				for(i=0; i<50; i++){
				cout << "\033[1;" << a << "m*\033[0m";
				}
	cout << "\n";
	}
	
}
void tab(int a){
	int i;
	for(i=0; i<a; i++){
		cout<< "\t";
	}
}
void side(int a, int b){
	int i;
	for(i=0; i<b; i++){
		cout << "\t";
	}
	cout << "\033[1;" << a << "m**\033[0m";
}
