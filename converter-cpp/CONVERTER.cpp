#include <iostream>
#include <conio.h>
#include <string>
#include <ctype.h>
#include <unistd.h>
#include <algorithm>
using namespace std;

typedef struct{
	char choice;
	int mark;
	char type[50];
}Var;

void menu(Var *var);
void menu2(Var *var);
void end(Var *var);
void Decimal_Octadecimal();
void Decimal_Binary();
void Decimal_Hexadecimal();
void Decimal_Hexadecimal();

int main(){
	Var var;
	loop://LOOP HERE
	system("cls");
	menu(&var);
	switch(var.choice){
		case '1':{//THIS CASE IS  FOR DECIMAL
			system("cls");
			dec://LOOP HERE 
			strcpy(var.type, "Decimal");
			var.mark = 1;
			menu2(&var);
			switch(var.choice){
				case 'B':{//decimal to binary
					try2:
					Decimal_Binary();
					loop2:
					end(&var);
					switch(var.choice){
						case '1':{
							goto try2;
							}
						case '2':{
							goto dec;
							}
						case '3':{
							return 0;
						}
						default:{
							cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
							sleep(2);
							goto loop2;
						}
					}
					break;
				}
				case 'O':{//decimal to octa decimal
					try1:
					Decimal_Octadecimal();
					loop1:
					end(&var);
					switch(var.choice){
						case '1':{
							goto try1;
							}
						case '2':{
							goto dec;
							}
						case '3':{
							return 0;
						}
						default:{
							cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
							sleep(2);
							goto loop1;
						}
					}
					break;
				}
				case 'H':{//decimal to hexadecimal
					try3:
					//Decimal_Hexadecimal();
					Decimal_Hexadecimal();
					loop3:
					end(&var);
					switch(var.choice){
						case '1':{
							goto try3;
							}
						case '2':{
							goto dec;
							}
						case '3':{
							return 0;
						}
						default:{
							cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
							sleep(2);
							goto loop3;
						}
					}
					break;
				}
				case 'G':{//LOOP
					goto loop;
					break;
				}
				case 'Q':{//QUIT THE PROGRAMM
					return 0;
				}
				default:{
					cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
					sleep(2);
					goto dec;
				}
			break;
			}}
		case '2':{//THIS CASE IS FOR BINARY
			bin://LOOP HERE 
			system("cls");
			strcpy(var.type, "Binary");
			var.mark = 2;
			menu2(&var);
			switch(var.choice){
				case 'D':{
					
					break;
				}
				case 'O':{
					
					break;
				}
				case 'H':{
					
					break;
				}
				case 'G':{//LOOP
					goto loop;
					break;
				}
				case 'Q':{//QUIT THE PROGRAMM
					return 0;
				}
				default:{
					cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
					sleep(2);
					goto dec;
				}
			}
			break;
		}
		case '3':{//THIS CASE IS FOR OCTA DDECIMAL
			oct://LOOP HERE 
			system("cls");
			strcpy(var.type, "Octa Decimal");
			var.mark = 3;
			menu2(&var);
			switch(var.choice){
				case 'D':{
					
					break;
				}
				case 'B':{
					
					break;
				}
				case 'H':{
					
					break;
				}
				case 'G':{//LOOP
					goto loop;
					break;
				}
				case 'Q':{//QUIT THE PROGRAMM
					return 0;
				}
				default:{
					cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
					sleep(2);
					goto dec;
				}
			}
			break;
		}
		case '4':{//THIS CASE IS FOR HEXADECIMAL
			hex://LOOP HERE 
			system("cls");
			strcpy(var.type, "Hexadecimal");
			var.mark = 4;
			menu2(&var);
			switch(var.choice){
				case 'D':{
					
					break;
				}
				case 'B':{
					
					break;
				}
				case 'O':{
					
					break;
				}
				case 'G':{//LOOP
					goto loop;
					break;
				}
				case 'Q':{//QUIT THE PROGRAMM
					return 0;
				}
				default:{
					cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
					sleep(2);
					goto dec;
				}
			}
			break;
		}
		case '5':{ //END THE CODE
			return 0;
		}
		default:{
			cout << "\n\n\tINVALID INPUT!!!\n\tTRY AGAIN\n\n";
			sleep(2);
			goto loop;
		}
	}
	goto loop;
	return 0;
}

void menu(Var *var){
	cout << "\tCONVERTER\n";
	cout << "[1] Decimal\n";
	cout << "[2] Binary\n";
	cout << "[3] Octa Decimal\n";
	cout << "[4] Hexadecimal\n";
	cout << "[5] Quit\n\n";
	var->choice = getch();
}
void menu2(Var *var){
	cout << "\t" << var->type << " Convert To...\n\n";
	if(var->mark!=1){
		cout << "[D] Decimal\n";
	}
	if(var->mark!=2){
		cout << "[B] Binary\n";
	}
	if(var->mark!=3){
		cout << "[O] Octa Decimal\n";
	}
	if(var->mark!=4){
		cout << "[H] Hexadecimal\n";
	}
	cout << "\n\n[G] Go Back\n";
	cout << "[Q] Quit";
	var->choice = getch();
	var->choice = toupper(var->choice);
}
void end(Var *var){
	cout << "\n\n[1] Try Again\n";
	cout << "[2] Go Back\n";
	cout << "[3] Quit\n\n";
	
	var->choice = getch();
	system("cls");
}
void Decimal_Binary(){
	int value, a, b, c=2, count=0, i;
	int store[30];
	system("cls");
	cout << "\tDecimal to Binary\n";
	cout << "\nEnter The Decimal Value: ";
	cin >> value;
	//formula to convert decimal to octa decimal
	while(value!=0){
		a = value/c;
		b = value%c;
		value = a;
		
		store[count] = b;
		count++;
	}
	cout << "\n\nBINARY: ";
	for(i=count-1; i>=0; i--){
		cout << store[i] << " ";
	}
}
void Decimal_Octadecimal(){
	int value, a, b, c=8.0, count=0, i;
	int store[20];
	system("cls");
	cout << "\tDecimal to Octa Decimal\n";
	cout << "\nEnter The Decimal Value: ";
	cin >> value;
	//formula to convert decimal to octa decimal
	while(value!=0){
		a = value/c;
		b = value%c;
		value = a;
		
		store[count] = b;
		count++;
	}
	cout << "\n\nOCTA DECIMAL: ";
	for(i=count-1; i>=0; i--){
		cout << store[i];
	}
	}
void Decimal_Hexadecimal(){
	int decimal, remainder;
	string hexadecimal;
	cout << "\n\tDecimal to Hexadecimal\n";
    cout << "\nEnter a decimal number: ";
    cin >> decimal;
    
    hexadecimal = "";

    while (decimal > 0) {
        remainder = decimal % 16;

        if (remainder < 10)
            hexadecimal += (remainder + '0');
        else
            hexadecimal += (remainder - 10 + 'A');

        decimal /= 16;
    }

    reverse(hexadecimal.begin(), hexadecimal.end());
    cout << "Hexadecimal: " << hexadecimal << endl;

}















