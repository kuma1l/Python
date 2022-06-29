#include"Project.h"
int main(){
	int choice = 0;
	ifstream fin;
	fin.open("Project.txt");
	int size = 10;
	Paragraph *arr = new Paragraph[size];
	int i = 0;
	while (choice != 6){
		Menu();
		cin >> choice;
		//Paragraph *ptr;
		if (choice == 1){
			system("CLS");
			fin >> arr[i];
			int innerChoice = 0;
			if (!fin.eof()){

				cout << "Paragraph Read." << endl;
			}
			else{
				cout << "No More Paragraphs left" << endl;
				innerChoice = -99;
			}
			bool conflag = false;
			bool encflag = false;
			bool upflag = false;
			bool smflag = false;
			bool decflag = false;
			bool compflag = false;
			int key = 0;
			while (innerChoice != -99){
				submenu();
				cin >> innerChoice;
				if (innerChoice == 1){
					system("CLS");
					ofstream fout;
					fout.open("Output.txt");
					fout << arr[i];
				}
				else if (innerChoice == 2){
					system("CLS");
					cout << arr[i] << endl;
				}
				else if (innerChoice == 3){
					system("CLS");
					int choice = 0;
					if (conflag == false)
					{
						while (choice != 1 || choice !=2){
							cout << "Press 1 to Convert UpperCase." << endl;
							cout << "Press 2 to Convert LowerCase." << endl;
							cin >> choice;
							if (choice == 1){
								+arr[i];
								conflag = true;
								upflag= true;
								smflag = false;
								cout << arr[i];
								break;
							}
							else if (choice == 2){
								-arr[i];
								conflag = true;
								smflag = true;
								upflag = false;
								cout << arr[i];
								break;
							}
							else
								cout << "Enter an Appropriate choice..!" << endl;
						}
					}
					else{
						if (upflag){
							cout << "Text is in UpperCase so converting it into smallcase." << endl;
							-arr[i];
							upflag = false;
							smflag = true;
							cout << arr[i] << endl;
						}
						else if (smflag){
							cout << "Text is in SmallCase so converting it into Uppercase." << endl;
							+arr[i];
							upflag = true;
							smflag = false;
							cout << arr[i] << endl;
						}
					}
				}
				else if (innerChoice == 4){
					system("CLS");
					cout << arr[i] << endl;
					arr[i].countpunc();
				}
				else if (innerChoice == 5){
					system("CLS");
					cout << arr[i] << endl;
					arr[i].countwords();
				}
				else if (innerChoice == 6){
					system("CLS");
					if (encflag == false){
						cout << "Enter an Encryption Key: ";
						cin >> key;
						encflag = true;
						arr[i] % key;
						cout << "Encrypted Paragraph is: " << endl;
						cout << arr[i] << endl;
						decflag = false;
					}
					else{
						cout << "Text is Already Encrypted.." << endl;
						
					}
				}
				else if (innerChoice == 7){
					int deckey = 0;
					if (decflag == false){
						system("CLS");
						cout << "Enter Decryption Key: ";
						cin >> deckey;
						arr[i] * deckey;
						cout << "Decrypted Paragraph is: " << endl;
						cout << arr[i] << endl;
						decflag = true;
						encflag = false;
					}
					else{
						system("CLS");
						cout << "Paragraph is Already Decrypted.." << endl;
						
					}
				}
				else if (innerChoice == 8){
					system("CLS");
					arr[i].wrdCheck();
				}
				else if (innerChoice == 9){
					system("CLS");
					!arr[i];
					compflag = true;
				}
				else if (innerChoice == 10){
					system("CLS");
					if (compflag){
						cout << "Decompressed Paragraph is: " << endl;
						arr[i] ^ 1;
						compflag = false;
					}
					else{
						cout << "Paragraph is already in Decompressed Form" << endl;
					}
				}
				else if (innerChoice == -99){
					system("CLS");
					break;
				}

				else{
					cout << "Enter an Appropriate Choice." << endl;
				}
			}
			i++;
		}
		else if (choice == 2){
			system("CLS");
			ifstream comp;
			comp.open("Project.txt");
			Paragraph *arr = new Paragraph[10];
			int i = 0;
			while (!comp.eof()){
				comp >> arr[i];
				i++;
			}
			int one;
			cout << "Enter No of Paragraph: ";
			cin >> one;
			int two;
			cout << "Enter No of Paragraph: ";
			cin >> two;
			cout << arr[one - 1] << endl;
			cout << arr[two - 1] << endl;
			if (arr[one-1] == arr[two-1]){
				cout << "Both Paragraphs are equal." << endl;
			}
			else{
				cout << "Both Paragraphs are not equal." << endl;
			}
			comp.close();
		}
		else if (choice == 3){
			system("CLS");
			ifstream plus;
			plus.open("Project.txt");
			Paragraph *arr = new Paragraph[10];
			int i = 0;
			while (!plus.eof()){
				plus >> arr[i];
				i++;
			}
			int one, two;
			cout << "Enter the Paragraph in which you want to add: ";
			cin >> one;
			cout << "Enter the Paragraph which will be added: ";
			cin >> two;
			//cout << arr[one - 1] << arr[two - 1];
			Paragraph p;
			p = arr[one - 1] + arr[two - 1];
			cout << p;
			plus.close();
		}
		else if (choice == 4){
			system("CLS");
			int Sentence_Count = -1;
			ifstream fin2;
			fin2.open("Project.txt");
			while (!fin2.eof()){
				Sentence s;
				fin2 >> s;
				Sentence_Count++;
			}
			cout << "Number of Sentences in File: ";

			cout << Sentence_Count << endl;
			fin2.close();
		}
		else if (choice == 5){
			system("CLS");
			int Word_Count = 1;
			ifstream fin2;
			fin2.open("Project.txt");
			while (!fin2.eof()){
				MyWord q;
				fin2 >> q;
				Word_Count++;
			}
			cout << "Number of words in File: " << Word_Count-1 << endl;
			fin2.close();
		}
		else if (choice == 6){
			Paragraph *arr = new Paragraph[6];
			ifstream all;
			int  i = 0;
			all.open("Project.txt");
			while (!all.eof()){
				cout << "Paragraph " << i + 1 << endl;
				all >> arr[i];
				arr[i].countwords(1);
				i++;
			}
		}
		else if (choice == 7){
			cout << "Program Ended.." << endl;
			break;
		}
		else
		{
			system("CLS");
			cout << "Enter an Appropriate Choice." << endl;
			
		}

	}
	return 0;
}