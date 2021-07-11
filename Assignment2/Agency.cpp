/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 29.04.2021
*/

#include <iostream>
#include <cstdlib>
#include "Agency.h"

using namespace std;

Agency::Agency(string name, int cash, int ticketPrice){
    this->name = name;
    this->cash = cash;
    if (ticketPrice > 0){
        this->ticketPrice = ticketPrice;
    }
    else {
        this->ticketPrice = 0;
        cout << "Ticket price can't be negative. It is set to 0." << endl;
    }
        
}

Agency::~Agency(){
    for(Mission* c = this->completedMissions; c ; ){
        Mission* temp = c;
        c = c->getNext();
        delete temp;
    }
    for(Mission* c = this->nextMissions; c ; ){
        Mission* temp = c;
        c = c->getNext();
        delete temp;
    }
}

void Agency::addMission(Mission mission){
    Mission* p = new Mission(mission);
    p->setNext(NULL);

    if (nextMissions == NULL){
        nextMissions = p;
    }
    else {
        Mission* traverse = nextMissions;
        while (traverse->getNext()){
            traverse = traverse->getNext();
        }
        traverse->setNext(p);
    }
    numNextMissions++;
}

void Agency::addCompletedMission(Mission* mission){
    if (completedMissions == NULL){
        completedMissions = mission;
    }
    else {
        Mission* traverse = completedMissions;
        while (traverse->getNext()){
            traverse = traverse->getNext();
        }
        traverse->setNext(mission);
    }
    numCompletedMissions++;
}

void Agency::addNextMission(Mission* mission){
    if (nextMissions == NULL){
        nextMissions = mission;
    }
    else {
        Mission* traverse = nextMissions;
        while (traverse->getNext()){
            traverse = traverse->getNext();
        }
        traverse->setNext(mission);
    }
    numNextMissions++;
}

void Agency::executeNextMission(){
    Mission* traverse = this->nextMissions;
    if (traverse == NULL){
        cout << "No available mission to execute!" << endl;
        return;
    }

    nextMissions = traverse->getNext();
    traverse->setNext(NULL);
    numNextMissions--;

    bool result = traverse->executeMission();
    if (result == true){
        this->addCompletedMission(traverse);
    }
    else {
        this->addNextMission(traverse);
        cout << "Agency reschedules the mission."<< endl;
    }
    int profit = traverse->calculateProfit(this->ticketPrice);
    this->cash += profit;
}

ostream& operator<<(ostream& out, Agency& agency){
    out << "Agency name: " << agency.getName() << ", Total cash: " << agency.getCash() 
                            << ", Ticket Price: "<< agency.getTicketPrice() << endl;
    
    out << "Next Missions:" << endl;
    Mission* traverse = agency.getNextMissions(); 
    for (int i=1; i <= agency.getNumNextMissions(); i++){
        out << "Mission number: " << traverse->getMissionNumber() << " Mission name: " << traverse->getName() << " Cost: " << traverse->getCost() << endl;
        traverse = traverse->getNext();
    }
    if (agency.numNextMissions == 0){
        out << "No missions available." << endl;
    }

    out << "Completed Missions:" << endl;
    traverse = agency.getCompletedMissions(); 
    for (int i=1; i <= agency.getNumCompletedMissions(); i++){
        out << "Mission number: " << traverse->getMissionNumber() << " Mission name: " << traverse->getName() << " Cost: " << traverse->getCost() << endl;
        traverse = traverse->getNext();
    }

    if (agency.numCompletedMissions == 0){
        out << "No missions completed before." << endl;
    }

    return out;
}