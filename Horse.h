#ifndef HORSE_H_
#define HORSE_H_

#include <cstdlib>
#include <iostream>
using namespace std;

/******************************************************************************
* Name    : class Horse
* Purpose : contains all variables and attributes for each horse
* Inputs  : none
* Outputs : class objects if ran successfully
******************************************************************************/

class Horse
{
	private:
		string name;
		string jockey;
		int maxSpeed;
		int distanceTraveled;
		int racesWon;
		int numHorses;
		double raceDistance;

	public:
		Horse(string, string);
		void setName(string);
		void setJockey(string);
		void setRacesWon(int);
		void setNumHorses(int);
		void runOneSecond();
		void sendToGate();
		void displayHorse(double);
		void setRaceDistance(double);
		~Horse();

		string getName() const
		{ return name; }

		string getJockey() const
		{ return jockey; }

		int getMaxSpeed() const
		{ return maxSpeed; }

		double getDistance() const
		{ return distanceTraveled; }

		double getRaceDistance() const
		{ return raceDistance; }

		int getRacesWon() const
		{ return racesWon; }

		int getNumHorses() const
		{ return numHorses; }
};

#endif /* HORSE_H_ */
