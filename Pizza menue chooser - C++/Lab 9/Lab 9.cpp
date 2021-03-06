// Lab 9.cpp : Defines the entry point for the console application.
//Kody Johnson
//Lab 9
//10/02/2017
//Pizza program
//determins which pizza has the lowest cost per square inch

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("inputPizza.txt");
	int numOfItems, menueNum = 0;

	//loops through the file for each menue item
	while (fin >> numOfItems)
	{
		//If the menue number is 0 then the file is finished and leaves the loop
		if (numOfItems == 0)
			break;

		//Generates the vars new each loop so the comparisons for each menue item is fresh
		float bestPizza = 9999;
		float tempPrice, tempDia, bestDia, tempPizza;

		//Itterate through the file for the number of items in each menue, does the math to determin the best vale per sqr inch
		for (int i = 0; i < numOfItems; i++)
		{
			//fin the items being checked
			fin >> tempDia >> tempPrice;
			//The math
			tempPizza = pow((tempDia/2),2) * 3.14;
			tempPizza = tempPrice / tempPizza * 100;
			//Comapares each item one by one to determin the lowest price per sqr inch and stores the value and the diameter 
			if (bestPizza > tempPizza)
			{
				bestPizza = tempPizza;
				bestDia = tempDia;
			}
		}
		// prints out the data for each itteration
		menueNum += 1;
		cout << "Menue " << menueNum << ": " <<bestDia << endl;
	}
	fin.close();
	system("pause");
	return 0;
}

