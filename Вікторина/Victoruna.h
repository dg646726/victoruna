#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Putanya {

	string question;
	string answer;


};

struct Victoruna{

	string name;
	Putanya* zaputannya;
};

void init();
void addVictorunu();
void showVictorunu();