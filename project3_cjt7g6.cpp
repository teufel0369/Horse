/******************************************************************************
 * Course       : CS 2250 E01 (Spring 2016)
 * Assignment   : Project 2
 * Summary      : This program will take in an English string and then convert
 * 				  that string to Pig Latin.
 * Author       : Christopher Thompson
 * Last Modified: 28 February 2016
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Horse.h"
using namespace std;

/******************************************************************************
* Name    : main()
* Purpose : Control the main loop for the game and prompt user for input
* Inputs  : none
* Outputs : returns 0 if ran successfully
******************************************************************************/

int main()
{
	int numH = 0;
	unsigned int i;
	double rD=0;
	double time = 0.0;
	string jN;
	string nombre;
	bool raceEnd = false;

	cout << "Welcome to the race track!\n\n"
	     << "Enter the number of horses in the race: ";
	cin >> numH;

	Horse** hPtr = new Horse*[numH]; //Array of pointers to horse objects

	for(i = 0; i < numH; i++){ //loop to create horse objects and initialize horse and jockey names

		cout << "Enter the name for horse " << (i+1) << ": ";
		cin >> nombre;
		cout << "Enter the name for jockey " << (i+1) << ": ";
		cin >> jN;
		hPtr[i] = new Horse(nombre, jN); //create new horse
	}

	cout << "Enter the distance of the race in meters: ";
	while(rD < 100 || rD > 1000){
		cin >> rD;
	}

	do  //main loop for the race
	{
		for(i = 0; i < numH; i++){

			cout << "Time: " << time << " seconds \n\n";
			hPtr[i]->runOneSecond();
			double dist = hPtr[i]->getDistance();
			hPtr[i]->displayHorse(rD);

			if(dist >= rD){ //Defining the end of the race
				raceEnd = true;

				if(raceEnd == true){
					cout << hPtr[i]->getName() << " ridden by " << hPtr[i]->getJockey() << " wins!!!";
				}
			}
		}

		time++;

	}while(!raceEnd); //while the race is still going

	for(i = 0; i < numH; i++){
		delete hPtr[i];
	}

	return 0;
}


