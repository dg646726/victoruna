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

	addVictorunu();
	showVictorunu();
	system("pause");
	return 0;
}