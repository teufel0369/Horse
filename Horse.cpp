#include "Horse.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstddef>
#include <cstdlib>
using namespace std;

/******************************************************************************
* Name    : Horse::Horse(string, string)
* Purpose : Constructor. Initializes variables
* Inputs  : struct Word and a string of words.
* Outputs : A dynamically allocated char array filled with words from a string
* 			if ran successfully.
******************************************************************************/

Horse::Horse(string horseName, string jockeyName)
{
	numHorses = 0;
	name = horseName;
	jockey = jockeyName;
	distanceTraveled = 0;
	maxSpeed = 1 + (rand() % 30); //random number initializes maxSpeed of the horse
	racesWon = 0;
	raceDistance = 0;
	srand(time(0)); //seed the random number generator with the time clock
}

/******************************************************************************
* Name    : Horse::setNumHorses(int)
* Purpose : sets the number of horses to run the race
* Inputs  : number of horses.
* Outputs : none.
******************************************************************************/

void Horse::setNumHorses(int numH_)
{
	numHorses = numH_;
}

/******************************************************************************
* Name    : Horse::setName(string)
* Purpose : sets the names of the horses
* Inputs  : Horse name
* Outputs : none
******************************************************************************/

void Horse::setName(string n)
{
	name = n;
}

/******************************************************************************
* Name    : Horse::setJockey
* Purpose : set the name of the jockey riding the horse
* Inputs  : Jockey name
* Outputs : none
******************************************************************************/

void Horse::setJockey(string j)
{
	jockey = j;
}

/******************************************************************************
* Name    : Horse::setRaceDistance
* Purpose : set the race distance
* Inputs  : raceDistance
* Outputs : none
******************************************************************************/

void Horse::setRaceDistance(double D)
{
	raceDistance = D;
}

/******************************************************************************
* Name    : Horse::runOneSecond
* Purpose : Adds to distance traveled a random amount between 0 and maxSpeed
* Inputs  : none
* Outputs : none
******************************************************************************/

void Horse::runOneSecond()
{
	distanceTraveled = distanceTraveled + (rand() % maxSpeed);
}

/******************************************************************************
* Name    : Horse::sendToGate()
* Purpose : resets distanceTraveled to 0, thus sending the horses to the gate
* Inputs  : none
* Outputs : none
******************************************************************************/

void Horse::sendToGate()
{
	distanceTraveled = 0;
}


/******************************************************************************
* Name    : Horse::displayHorse(double)
* Purpose : To display the output of each horse relational to the size of the
* 			screen.
* Inputs  : raceDistance
* Outputs : none
******************************************************************************/

void Horse::displayHorse(double raceDistance)
{
	int distance;
	double denom = raceDistance / 40;
	int currentPos = (distanceTraveled / denom);


	cout <<  name << " ridden by " << jockey <<"  |";

	for(int i = 0; i < 40; i++){

		if(i == 39 && (currentPos-1) >= i){
			cout << "|>";
		}

		else if(i < currentPos - 1){
			cout << '-';
		}
		else if(i == currentPos - 1){
			cout << '>';
		}
		else if(i > currentPos - 1){
			cout << ' ';
		}
	}

	cout << endl;

}


/******************************************************************************
* Name    : Horse::~Horse()
* Purpose : Destructor. Deallocates all horse objects
* Inputs  : none
* Outputs : none
******************************************************************************/

Horse::~Horse()
{

}
