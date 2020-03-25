#include "Victoruna.h"
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define CLEAR system("cls")
#define PAUSE system("pause")
#define ENDL cout<<endl

Victoruna* victorunu;
int countVictorun = 0;

//void init()
//{
//	ifstream fin;
//	fin.open("Quiz.txt");
//	bool isOpen = fin.is_open();
//
//	if (isOpen == false) {
//		cout << "Error" << endl;
//	}
//	else {
//		int currentString = 0;
//		string data;
//		while (!fin.eof()) {
//			currentString++;
//
//			getline(fin, data);
//			if (currentString == 1) {
//
//			}
//			else if (currentString == 2) {
//
//			}
//			else if (currentString == 3) {
//
//			}
//			else if (currentString == 4) {
//
//			}
//			else if (currentString == 5) {
//
//			}
//			else if (currentString == 6) {
//
//			}
//			else if (currentString == 7) {
//
//			}
//			else if (currentString == 8) {
//
//			}
//			else if (currentString == 9) {
//
//			}
//			else if (currentString == 10) {
//
//			}
//			else if (currentString == 11) {
//
//			}
//			else {
//				
//				old_data.password = data;
//				currentString = 0;
//				login_details.push_back(old_data);
//				old_data = LoginDetails();
//			}
//		}
//	}
//}

void addVictorunu()
{
	ofstream fout;
	fout.open("Quiz.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Victoruna* temp = new Victoruna[countVictorun + 1];
		for (int i = 0; i < countVictorun; i++)
		{
			temp[i] = victorunu[i];
		}

		cout << "Enter name victorunu:";
		cin >> temp[countVictorun].name;

		temp[countVictorun].zaputannya = new Putanya[5];
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter question"<<i+1<<"/5:";
			cin >> temp[countVictorun].zaputannya[i].question;
			cout << "Enter correct answer:";
			cin >> temp[countVictorun].zaputannya[i].answer;
		}
		
		fout << temp[countVictorun].name << endl;
		for (int i = 0; i < 5; i++)
		{
			fout << temp[countVictorun].zaputannya[i].question << endl;
			fout << temp[countVictorun].zaputannya[i].answer << endl;

		}
		
		fout.close();
		countVictorun++;
		delete victorunu;
		victorunu = temp;
	}
	else {
		cout << "Error: file not open." << endl;
	}
}

void showVictorunu()
{
	cout << "List victorun:" << endl;
	for (int i = 0; i < countVictorun; i++)
	{
		cout << victorunu[i].name << endl;
	}
	string output;
	cout << "Enter name victorunu to which you want to answer:";
	cin >> output;
	string correctAnswer;
	int countCorrectAnswer = 0;
	for (int i = 0; i < countVictorun; i++)
	{
		if (output == victorunu[i].name) {
			ENDL;
			cout << victorunu[i].name << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << i + 1 << ". " << victorunu[i].zaputannya[j].question << endl;
				cin >> correctAnswer;
				if (correctAnswer == victorunu[i].zaputannya[j].answer) {
					countCorrectAnswer++;
				}
			}
			if (countCorrectAnswer == 5) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN);
				cout << "Good job. All answer correct" << endl;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (countCorrectAnswer >= 3) {
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
				cout << "Not bad. " << countCorrectAnswer << " correct answer" << endl;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else {
				SetConsoleTextAttribute(color, FOREGROUND_RED);
				cout << "Bad. Try better next time" << endl;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
		}

	}
}
