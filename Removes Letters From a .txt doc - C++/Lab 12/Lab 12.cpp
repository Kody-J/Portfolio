// Lab 12.cpp : Defines the entry point for the console application.
/*

Kody Johnson
Lab 12
11/30/2017

*/

#include "stdafx.h"
#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void fillList(list<char>& thing, string a);
void printList(list<char> thing, ostream& out);
void removeCharacter(list<char>& thing, char target);

int main()
{
	//File handle for input.txt
	ifstream fin("input.txt");
	//Output file
	ofstream fout("output.txt");

	//Used to read in each line from input.txt
	string tempData; 

	//Check to see if the file is valid, sends a warning if not valid then closes program
	if (!fin.good())
	{
		cout << "Could not open File!" << endl;
		return -1;
	}

	// Iterates through the input.txt untill its empty
	while (fin.good())
	{
		getline(fin, tempData);
		if (tempData == "END")
			break;

		// Creates a new list for each item in the input.txt file
		list<char>charList;

		//Converts the string into a list of characters
		fillList(charList, tempData);

		//Removes any char item with List if characters (all vowels for this program)
		removeCharacter(charList, 'a');
		removeCharacter(charList, 'e');
		removeCharacter(charList, 'i');
		removeCharacter(charList, 'o');
		removeCharacter(charList, 'u');

		// Outputs the list into a txt file
		printList(charList, fout);
	}

    return 0;
}

// Iterates over a string and modifies the list to add the string contents
void fillList(list<char>& thing, string a)
{
	for (string::iterator itr = a.begin(); itr != a.end(); ++itr)
		thing.push_back(*itr);
}

// Iterates through the list and outputs its characters into a txt file
void printList(list<char> thing, ostream &out)
{
	for (list<char>::iterator itr = thing.begin(); itr != thing.end(); ++itr)
	{
		out << "[" << *itr << "] -> ";
	}
	// Shows the last element to be 0 for nullptr
	out << "0 \n" << endl;
}

// Iterates through the list, checks each item if it matches the target item, removes it from the list
void removeCharacter(list<char>& thing, char target)
{
	//Removes both uper and lowercase items
	thing.remove(toupper(target));
	thing.remove(tolower(target));
}
