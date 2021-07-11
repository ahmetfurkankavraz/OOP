/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 29.04.2021
*/

#pragma once

#include <iostream>
#include <cstdlib>
#include "Person.h"

using namespace std;

class Mission{
    static int numMissions;
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed = false;

    Passenger* passengers = NULL;
    int passengersSize = 0;

    Astronaut* crew = NULL;
    int crewSize = 0;

    Mission* next = NULL;
    
    public:
        Mission(string, int, int);
        Mission(const Mission&); 
        ~Mission();
        
        Mission* operator+=(Passenger*);
        Mission* operator+=(Astronaut*);
        bool executeMission();
        int calculateProfit(int);

        void addPassenger(Passenger);
        void addAstronaut(Astronaut);
        void printPassengers();
        void printCrew();

        string getName(){return this->name;}
        void setName(string);
        bool properName(string);
        int getCost(){return cost;}
        void setCost(int cost){this->cost = cost;}
        int getMissionNumber(){return missionNumber;}
        void setMissionNumber(int missionNumber){this->missionNumber = missionNumber;}
        int getFaultProbability(){return faultProbability;}
        void setFaultProbability(int faultProbability){this->faultProbability = faultProbability;}
        Astronaut* getCrew(){return crew;}
        void setCrew(Astronaut* crew){this->crew = crew;}
        int getCrewSize(){return this->crewSize;}
        void setCrewSize(int crewSize){this->crewSize = crewSize;}
        Passenger* getPassengers(){return passengers;}
        void setPassengers(Passenger* passengers){this->passengers = passengers;}
        Mission* getNext(){return this->next;}
        void setNext(Mission* next){this->next = next;}
};
