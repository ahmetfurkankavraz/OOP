/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 29.04.2021
*/

#include <iostream>
#include <cstdlib>
#include "Mission.h"
#include "Person.h"

using namespace std;

Mission::Mission(string name, int cost, int faultProbability){

    this->setName(name);
    this->missionNumber = ++numMissions;
    this->cost = cost;
    this->faultProbability = faultProbability;
}

Mission::Mission(const Mission& mission){
    this->name = mission.name;
    this->missionNumber = mission.missionNumber;
    this->cost = mission.cost;
    this->faultProbability = mission.faultProbability;
    this->completed = mission.completed;
    this->setNext(NULL);

    for (Passenger* traverse2 = mission.passengers; traverse2; traverse2 = traverse2->getNext() ){
        this->addPassenger(*traverse2);
    }

    for (Astronaut* traverse = mission.crew; traverse; traverse = traverse->getNext()){
        this->addAstronaut(*traverse);
    }
}

Mission::~Mission(){
    for(Astronaut* c = this->crew; c ; ){
        Astronaut* temp = c;
        c = c->getNext();
        delete temp;
    }
    for(Passenger* c = this->passengers; c ; ){
        Passenger* temp = c;
        c = c->getNext();
        delete temp;
    }
}

Mission* Mission::operator+=(Passenger* passenger){
    if (passenger->getTicket() == true){
        addPassenger(*passenger);
    }
    else {
        cerr << "Passenger " << passenger->getName() << " " << passenger->getSurname() << " does not have a valid ticket!" << endl;
    }

    return this;
}

Mission* Mission::operator+=(Astronaut* astronaut){
    addAstronaut(*astronaut);
    return this;
}

void Mission::addPassenger(Passenger passenger){
    Passenger* p = new Passenger(passenger);
    p->setNext(NULL);
    if (passengers == NULL){
        passengers = p;
    }
    else {
        Passenger* traverse = passengers;
        while (traverse->getNext()){
            traverse = traverse->getNext();
        }
        traverse->setNext(p);
    }
    passengersSize++;
}

void Mission::addAstronaut(Astronaut astronaut){
    Astronaut* p = new Astronaut(astronaut);
    p->setNext(NULL);
    if (crew == NULL){
        crew = p;
    }
    else {
        Astronaut* traverse = crew;
        while (traverse->getNext()){
            traverse = traverse->getNext();
        }
        traverse->setNext(p);
    }
    crewSize++;
}

void Mission::printPassengers(){
    for (Passenger* p = passengers; p; p = p->getNext()){
        cout << p->getName() << " " << p->getSurname() << endl;
    }
}
void Mission::printCrew(){
    for (Astronaut* p = crew; p; p = p->getNext()){
        cout << p->getName() << " " << p->getSurname() << endl;
    }
}

bool Mission::executeMission(){

    int randomNum = rand() % 100;
    if (randomNum > faultProbability){
        
        completed = true;
        cout << "MISSION " << name << " SUCCESSFUL!" << endl;

        Astronaut* traverse = crew;
        for (int i = 0; i < crewSize; i++){
            traverse->completeMission();
            cout << "Astronaut "<< traverse->getName() << " "<< traverse->getSurname() <<" successfully completed "<< traverse->getNumMissions() <<" missions."<< endl;
            traverse = traverse->getNext();
        }
    }
    else {
        cout << "MISSION " << name << " FAILED!" << endl;
    }
    return this->completed;
}

int Mission::calculateProfit(int ticketPrice){
    int totalProfit = 0;
    if (this->completed == true){
        totalProfit += ticketPrice * passengersSize;
    }
    totalProfit -= this->cost;
    return totalProfit;
}

void Mission::setName(string name){
    if (properName(name) == true){
        this->name = name;
    }
    else {
        cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
        this->name = "AA-00";
    }
}

bool Mission::properName(string name){
    bool isTypeTrue = true;

    if (name.length() != 5){
        isTypeTrue = false;
    }
    for (int i = 0; isTypeTrue == true && i < 5; i++){
        
        if (i == 0 || i == 1){
            if (name[i] < 'A' || name[i] > 'Z'){
                isTypeTrue = false;
            }
        }
        else if (i == 2){
            if (name[i] != '-' ){
                isTypeTrue = false;
            }
        }
        else {
            if (name[i] < '0' || name[i] > '9'){
                isTypeTrue = false;
            }
        }
    }

    return isTypeTrue;
}