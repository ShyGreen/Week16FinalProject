#include "BaseScore.h"
#include<iostream>
using namespace std;
//---default constructor
BaseScore::BaseScore()
{
	home = 0;
	guest = 0;
	timeTotal = 10.00;
	timeLeft = 10.00;
}
//---constructor that sets it with values from the user
BaseScore::BaseScore(double scoreH, double scoreG, double time)
{
	home = scoreH;
	guest = scoreG;
	timeTotal = time;
	timeLeft = time;
}
//---these getters and setters are pretty self explanatory
void BaseScore::setHome(double scoreH)
{
	home = scoreH;
}

double BaseScore::getHome()
{
	return home;
}

void BaseScore::setGuest(double scoreG)
{
	guest = scoreG;
}

double BaseScore::getGuest()
{
	return guest;
}
void BaseScore::setTime(double time)
{
	timeTotal = time;
	timeLeft = time;
}
//---display all the variables of the class and scores | it doesn't show off total time as scoreboards don't show them
void BaseScore::displayScore()
{
	cout << "---Score Info---\n";
	cout << "Home Score       : " << home << endl;
	cout << "Guest Score      : " << guest << endl;
	cout << "Time Left        : " << timeLeft << endl;
}
