/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 29.04.2021
*/

#pragma once

#include <iostream>
#include <cstdlib>
#include "Person.h"
#include "Mission.h"

using namespace std;

class Agency{
    string name;
    int cash;
    int ticketPrice;

    Mission* completedMissions = NULL;
    int numCompletedMissions = 0;
    
    Mission* nextMissions = NULL;
    int numNextMissions = 0;

    public:
        Agency(string, int, int);
        ~Agency();

        void addMission(Mission);
        void addCompletedMission(Mission*);
        void addNextMission(Mission*);
        void executeNextMission();
        friend ostream& operator<<(ostream&, Agency&);

        string getName(){return this->name;}
        void setName(string);
        int getCash(){ return this->cash;}
        void setCash(int cash){ this->cash = cash;}
        int getTicketPrice(){return this->ticketPrice;}
        void setTicketPrice(int ticketPrice){this->ticketPrice = ticketPrice;}
        
        Mission* getCompletedMissions(){return this->completedMissions;}
        void setCompletedMissions(Mission* completedMissions){this->completedMissions = completedMissions;}
        int getNumCompletedMissions(){return this->numCompletedMissions;}
        void setNumCompletedMissions(int numCompletedMissions){this->numCompletedMissions = numCompletedMissions;}

        Mission* getNextMissions(){return this->nextMissions;}
        void setNextMissions(Mission* nextMissions){this->nextMissions = nextMissions;}
        int getNumNextMissions(){return this->numNextMissions;}
        void setNumNextMissions(int numNextMissions){this->numNextMissions = numNextMissions;}
        

};