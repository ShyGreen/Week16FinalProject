#pragma once
#include "BaseScore.h"
class BasketballScore : public BaseScore
{
private:
	int homeFouls, guestFouls, period, match;
	double homeHits, homeMisses, guestHits, guestMisses;
	bool homeBonus, guestBonus;//---if the other team has more than 7 fouls each foul after will give the other team a free shot | these are set automatically set at the setFoul functions and can't be set manually
public:
	//---See the .cpp to see what the functions do
	BasketballScore();
	BasketballScore(int, int, int, int, double, double, double, double);
	void setHomeFouls(int);
	int getHomeFouls();
	void setGuestFouls(int);
	int getGuestFouls();
	void setPeriod(int);
	int getPeriod();
	void setMatch(int);
	int getMatch();
	void setHomeHits(double);
	double getHomeHits();
	void setHomeMisses(double);
	double getHomeMisses();
	void setGuestHits(double);
	double getGuestHits();
	void setGuestMisses(double);
	double getGuestMisses();
	void setAll(int, int, int, int, double, double, double, double);
	void seeBonus();
	void displayScore();
};

