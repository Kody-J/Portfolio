// ConsoleApplication1.cpp : Defines the entry point for the console application.
// Library books checked out and in simulator
/* 

This is a simple program which starts with a .txt file that conatins All the students and the books they have checked out
Then a list of checkins is provided, Based on the students ID the book is removed from their check out list and the availiable books list is updated
Then a list of check outs is provided, the book is found to be either available or not then checked out. The students book list is updated

*/
#include "stdafx.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void resizeArray(User *&UA, int &s);
void sortArray(User *&usrArray, int size);
int searchArray(User *&usrArr, int size, int usrID);

int main()
{
	ifstream fin("users.txt");
	ifstream fin2("checkouts.txt");
	ifstream fin3("checkins.txt");
	ofstream fout("updated_Users.txt");

	int sizeOfUsrArray = 10;
	int itemsInUsrArray = 0;
	User* usersArray = new User[10];

	

	//Determins if the files are valid
	if (!fin || !fin2 || !fin3)
	{
		cout << "A file could not be opened" << endl;
		system("pause");
		return 1;
	}
	//Goes throught the user file and creats objects out of them, and places them into the usersArray.
	//If the userArray becomes full, the array size is doubled using resizeArray function
	while (fin >> usersArray[itemsInUsrArray])
	{
		itemsInUsrArray += 1;
		if (itemsInUsrArray == sizeOfUsrArray)
		{
			resizeArray(usersArray, sizeOfUsrArray);
		}
	}
	// sorts the usersArray numerically, by IDNumber
	sortArray(usersArray, itemsInUsrArray);

	int tempID;
	while (fin2 >> tempID)
	{
		int idxFound = searchArray(usersArray, itemsInUsrArray, tempID);
		if (idxFound == -1)
		{
			cerr << "No user can be found with this ID number: " << tempID << endl;
		}
		else
		{
			string tempBook;
			fin2 >> tempBook;
			usersArray[idxFound].checkOut(tempBook);
		}
	}

	string tempBook;//holder for each book
	while (fin3 >> tempBook)
	{
		vector <User> usrCheckOutHold(0); //hold onto the users with the book being checked in, in case there is multiple
		for (int i = 0; i < itemsInUsrArray; i++)//Loops the users Array to look for a book to check in  
		{
			if(usersArray[i].checkIn(tempBook) == true)
				usrCheckOutHold.push_back(usersArray[i]);//places the user in a holding vector untill all users have been examined for the book being checked in
		}

		if (usrCheckOutHold.size() < 1)//If the holding vector is empty then no user was found and an error is displayed
			cerr << "No user can be found with this item checked out: " << tempBook << endl;

		else if (usrCheckOutHold.size() > 1) //Displays an error msg if more than one user has the book checked out, but still checks in the book for all
		{
			cerr << "This item is checked out by more than one user: ";
			for (int i = 0; i < usrCheckOutHold.size(); i++)
			{
				cerr << usrCheckOutHold[i].getIdNumber() << endl;
			}
		}
		else //If book is found in only one users Array of checked out books then simply check it in for the user
		{
			usrCheckOutHold[0].checkIn(tempBook);
		}

	}
	

	// Sends the information of each object in Users Array to a output file 
	for (int i = 0; i < itemsInUsrArray; i++)
	{
		fout << usersArray[i];
	}

	fin.close();
	fin2.close();
	fin3.close();
	return 0;
}

//Used to sort the usersArray by order of ID number
void sortArray(User *&usrArray, int size)
{
	for (int i = 1; i < size - 1; i++)
	{
		int j = i;
		while (j > 0 && usrArray[j].getIdNumber() < usrArray[j - 1].getIdNumber())
		{
			swap(usrArray[j], usrArray[j - 1]);
			j = j - 1;
		}

	}

}

//Adjusts the size of the usersArray if the array becomes full. (doubles its size)
void resizeArray(User *&usrArr, int &size)
{
	User *resized = new User[size * 2];
	for (int i = 0; i < size; i++)
		resized[i] = usrArr[i];
	size = size * 2;
	usrArr = resized;
}


//Used to search the user Array for a spacific ID
int searchArray(User *&usrArr, int size, int usrID)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = floor((left + right) / 2);
		if (usrArr[mid].getIdNumber() == usrID)
			return mid;
		else if (usrArr[mid].getIdNumber() < usrID)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

