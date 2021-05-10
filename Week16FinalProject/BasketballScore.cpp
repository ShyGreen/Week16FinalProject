#include "BasketballScore.h"
#include<iostream>
using namespace std;

//---default constructor when no vlaues are used
BasketballScore::BasketballScore()
{
	homeFouls = 0;
	guestFouls = 0;
	period = 1;
	match = 1;
	homeBonus = false;
	guestBonus = false;
}

BasketballScore::BasketballScore(int hf, int gf, int p, int m, double hh, double hm, double gh, double gm)
{
	homeFouls = hf;
	guestFouls = gf;
	period = p;
	match = m;
	if (homeFouls >= 7)
		guestBonus = true;
	else
		guestBonus = false;

	if (guestFouls >= 7)
		homeBonus = true;
	else
		homeBonus = false;

	homeHits = hh;
	homeMisses = hm;
	guestHits = gh;
	guestMisses = gm;
}
//---set the home fouls | if it is equal or greater than 7 set guestBonus to true | see the .h file as to why
void BasketballScore::setHomeFouls(int hf)
{
	homeFouls = hf;
	if (homeFouls >= 7)
		guestBonus = true;
}

int BasketballScore::getHomeFouls()
{
	return homeFouls;
}
//---set the guest fouls | if it is equal or greater than 7 set homeBonus to true | see the .h file as to why
void BasketballScore::setGuestFouls(int gf)
{
	guestFouls = gf;
}

//---The rest of these getters and setters are pretty self explanatory
int BasketballScore::getGuestFouls()
{
	return guestFouls;
}

void BasketballScore::setPeriod(int p)
{
	period = p;
}

int BasketballScore::getPeriod()
{
	return period;
}

void BasketballScore::setMatch(int m)
{
	match = m;
}

int BasketballScore::getMatch()
{
	return match;
}
void BasketballScore::setHomeHits(double hh)
{
	homeHits = hh;
}
double BasketballScore::getHomeHits()
{
	return homeHits;
}
void BasketballScore::setHomeMisses(double hm)
{
	homeMisses = hm;
}
double BasketballScore::getHomeMisses()
{
	return homeMisses;
}
void BasketballScore::setGuestHits(double gh)
{
	guestHits = gh;
}
double BasketballScore::getGuestHits()
{
	return guestHits;
}
void BasketballScore::setGuestMisses(double gm)
{
	guestMisses = gm;
}
double BasketballScore::getGuestMisses()
{
	return guestMisses;
}
//---Same as constructor but it can be used anytime and set up afterwards
void BasketballScore::setAll(int hf, int gf, int p, int m, double hh, double hm, double gh, double gm)
{
	homeFouls = hf;
	guestFouls = gf;
	period = p;
	match = m;
	if (homeFouls >= 7)
		guestBonus = true;
	else
		guestBonus = false;

	if (guestFouls >= 7)
		homeBonus = true;
	else
		homeBonus = false;

	homeHits = hh;
	homeMisses = hm;
	guestHits = gh;
	guestMisses = gm;
}

//---check if both teams do or do not have a bonus | this can also bee seen in the display info function
void BasketballScore::seeBonus()
{
	if (homeBonus == true)
		cout << "Home team has a bonus" << endl;
	else
		cout << "Home team does not have a bonus" << endl;

	if (guestBonus == true)
		cout << "Guest team has a bonus" << endl;
	else
		cout << "Guest team does not have a bonus" << endl;
}
//--- display info from the BasketballScore class | it also calls the base class' displayInfo to show thier score
void BasketballScore::displayScore()
{
	BaseScore::displayScore();//---call the base classes display info file to show off the regular score and times
	cout << "Home Fouls       : " << homeFouls << endl;
	cout << "Guest Fouls      : " << guestFouls << endl;
	cout << "Period           : " << period << endl;
	cout << "Match            : " << match << endl;
	if (homeBonus == true)
		cout << "Home team has a bonus" << endl;
	else
		cout << "Home team does not have a bonus" << endl;

	if (guestBonus == true)
		cout << "Guest team has a bonus" << endl;
	else
		cout << "Guest team does not have a bonus" << endl;
}
