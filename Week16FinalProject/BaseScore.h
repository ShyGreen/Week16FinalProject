#pragma once
class BaseScore
{
private:
	double home, guest, timeTotal, timeLeft;
public:
	//---see the .cpp file to see what the functions do
	BaseScore();
	BaseScore(double, double, double);
	void setHome(double);
	double getHome();
	void setGuest(double);
	double getGuest();
	void setTime(double);
	void displayScore();
};

