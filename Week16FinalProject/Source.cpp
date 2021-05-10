// Collin McGhee
// CIS 1202
// May 9 2021
#include<iostream>
#include<string>
#include<fstream>//---for writing and saving files
#include"BaseScore.h"//---add in the baseScore class | it won't be used though as we will be using the derived class BasketballScore
#include"BasketballScore.h"
using namespace std;

//----! FUNCTIONS !-----
//---show the user a menu and return a choice from them to be used
int displayMenu()
{
	int choice = 0;
	cout << "1. Set Basketball Scores\n2. Display Basketball Scores\n3. Save Scores to a File\n4. Open Saved Scores\n5. See Teams Hit/Miss Ratio\n6. Quit Program\n";
	//---get the choice from the user
	cout << "Enter your choice here -->: ";
	cin >> choice;
	//---check if the number is in range | if not ask the user to re-enter it
	while (choice < 1 || choice > 6)
	{
		cout << "Please enter a number between 1 and 6. Please re-enter your choice\n";
		cout << "Please re-enter here -->: ";
		cin >> choice;
	}
	return choice;
}

//----! MAIN !-----
int main()
{
	//----! Variables !----
	int menu;
	BasketballScore bball;
	fstream file;
	file.open("basketballscores.dat", ios::in | ios::out | ios::binary | ios::trunc);

	//---the user will be asked what these values are and enter them into the class object
	int home, guest, timeTotal, homeFouls, guestFouls, period, match;
	double homeHits, homeMisses, guestHits, guestMisses;
	double ratio = 0;
	bool homeBonus, guestBonus;

	//----! Loop !----
	while (true)
	{
		menu = displayMenu();//---call the menu to get a choice for the switch menu
		cout << endl;
		switch (menu)
		{
		//---Get and Set Scores
		case 1:
		{
			cout << "Please enter Home Score -->: ";
			cin >> home;
			cout << endl;
			cout << "Please enter Guest Score -->: ";
			cin >> guest;
			cout << endl;
			cout << "Please enter Length of match -->: ";
			cin >> timeTotal;
			cout << endl;
			cout << "Please enter Home Fouls -->: ";
			cin >> homeFouls;
			cout << endl;
			cout << "Please enter Guest Fouls -->: ";
			cin >> guestFouls;
			cout << endl;
			cout << "Please enter the Period -->: ";
			cin >> period;
			cout << endl;
			cout << "Please enter the number of the Match -->: ";
			cin >> match;
			cout << endl;

			cout << "Please enter amount of baskets the Home Team Made -->: ";
			cin >> homeHits;
			cout << endl;
			cout << "Please enter amount of baskets the Home Team Missed -->: ";
			cin >> homeMisses;
			cout << endl;
			cout << "Please enter amount of baskets the Guest Team Made -->: ";
			cin >> guestHits;
			cout << endl;
			cout << "Please enter amount of baskets the Guest Team Missed -->: ";
			cin >> guestMisses;
			cout << endl;

			bball.setAll(homeFouls, guestFouls, period, match, homeHits, homeMisses, guestHits, guestMisses);
			bball.setHome(home);
			bball.setGuest(guest);
			bball.setTime(timeTotal);

			break;
		}
		//---Display Scores
		case 2:
		{
			bball.displayScore();
			break;
		}
		//---Save Scores to a file
		case 3:
		{
			file.clear();
			file.seekp(0);
			file.write(reinterpret_cast<char*>(&bball), sizeof(bball));
			cout << "Scores saved to 'basketballscores.dat'\n";
			break;
		}
		//---open scores from a file
		case 4:
		{
			file.clear();
			file.seekg(0);
			while (!file.eof())
			{
				file.read(reinterpret_cast<char*>(&bball), sizeof(bball));
				cout << "Read data from 'basketballscores.dat', ready to display scores.\n";
			}
			break;
		}
		//---Hit/Miss ratio
		case 5:
		{
			ratio = bball.getHomeHits() / bball.getHomeMisses();
			cout << "Home Team Hit/Miss Ration is : " << ratio;
			cout << endl;
			ratio = bball.getGuestHits() / bball.getGuestMisses();
			cout << "Guest Team Hit/Miss Ration is : " << ratio;
			cout << endl;
			break;
		}
		//---Quit option
		case 6:
		{
			cout << "Thank you for using this program!\n";
			file.close();
			system("pause");
			return 0;
		}
		}
		cout << "------------------------------------------------------------------------------\n";
	}
}