// Assignment VI.cpp : Defines the entry point for the console application.
//
/*
Kody Johnson
Assignment VI

Starting with 13 tokens, ask user to input a target value and a number of turns. 
By either subtracting total amount of tokens by half or adding 25 more tokens to 
the total each tern, determin if there is a valid soultion, and output the 
solution to the user.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

void tokenGame(int target, int tokens, int terns);

int main()
{
	bool playGame = true;

	// Main loop, continues to play till the user is finsihed
	while (playGame)
	{
		// Vars used to store the number of tokens and terns usr desires
		int usrTarget, usrTerns;
		// Var used to determine if the usr wants to play again
		char usrInput;
		// Usr interface 
		cout << "Enter the number of tokens you want to reach: " << endl;
		cin >> usrTarget;
		cout << "What is the number of terns: " << endl;
		cin >> usrTerns;
		cout << "Searching for a solution within " << usrTerns << " turn(s)..." << endl;

		// Function used to determin if a solution can be found
		tokenGame(usrTarget, 13, usrTerns);
		//Asks the user if the wish to play again
		cout << "Would you like to play again? [Y/N] " << endl;
		cin >> usrInput;

		//Checks if user made valid input
		while (usrInput != 'Y' && usrInput != 'y' && usrInput != 'N' && usrInput != 'n')
		{
			cout << "Please make a valid input: [Y/N] " << endl;
			cin >> usrInput;
		}
		if (usrInput == 'Y' || usrInput == 'y')
			playGame = true;
		else
			playGame = false;
	}

	cout << "Thanks for playing!" << endl;
	system("pause");

    return 0;
}

// Takins in user inputs. Then recursively tries to find a valid solution.
 void tokenGame(int target,int tokens, int terns)
{
	 // Checks if solution was found (Base case 1)
	if (tokens == target)
	{
		cout << "Solution found with " << terns << " turn(s) remaining." << endl;
		return;
	}
	// Checks if number of terns has run out (Base case 2)
	else if (terns < 1 && tokens != target)
	{
		cout << "Sorry, a solution wasn't found within the allotted turns." << endl;
		return;
	}
	// If the number of tokens is 13 and less than or EQUAL to 2x the target, add 25 to number of tokaens
	else if( tokens == 13 && tokens / 2 != target)
	{
		cout << "Adding 25, you get " << tokens + 25 << " tokens." << endl;
		tokenGame(target, tokens + 25, terns - 1);

	}
	// If the number tokens + 25 is less than or EQUAL to  2x the target, add 25 to number of tokaens
	else if (tokens + 25 <= (2 * target)) {
		cout << "Adding 25, you get " << tokens + 25 << " tokens." << endl;
		tokenGame(target, tokens + 25, terns - 1);
	}
		
	else
	{
		cout << "Reducing by half, you get " << tokens / 2 << " tokens." << endl;
		tokenGame(target, tokens / 2, terns - 1);;
	}
		
}
