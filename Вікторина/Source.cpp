#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
#include "Victoruna.h"


using namespace std;

#define CLEAR system("cls")
#define PAUSE system("pause")
#define ENDL cout<<endl


int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));

	init();
	int action = 0;

	do {

		cout << "1.Add new quiz" << endl;
		cout << "2.Show and pass quiz" << endl;
		cout << "3.Exit" << endl;
		ENDL;
		cout << "Select action:";
		cin >> action;
		switch (action) {
		case 1:
			addVictorunu();
			break;
		case 2:
			showVictorunu();
			break;
		case 3:
			cout << "Goodbye" << endl;
			break;
		default:
			cout << "Error" << endl;
		}
	} while (action != 3);
	system("pause");
	return 0;
}