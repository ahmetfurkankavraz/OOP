/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 29.04.2021
*/

#include <iostream>
#include <cstdlib>
#include "Person.h"

using namespace std;

Person::Person(string name, string surname){
    this->name = name;
    this->surname = surname;
}

Passenger::Passenger(string name, string surname, int cash) : Person(name,surname) {
    if (cash >= 0)
        this->cash = cash;
    else{
        this->cash = 0;
        cerr << "Passenger cash can’t be negative. It is set to 0." << endl;
    }
}

Passenger::Passenger(string name, string surname): Person(name,surname){
    this->cash = 0;
}

void Passenger::buyTicket(int ticketPrice){
    if (this->cash >= ticketPrice){
        this->cash -= ticketPrice;
        this->ticket = true;
    }
}

Astronaut::Astronaut(string name, string surname, int numMissions): Person(name,surname){
    if (numMissions >= 0){
        this->numMissions = numMissions;
    } 
    else {
        cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
        this->numMissions = 0;
    }
    
}

Astronaut::Astronaut(string name, string surname) : Person(name,surname){
    this->numMissions = 0;
}


void Astronaut::completeMission(){
    this->numMissions += 1;
}

