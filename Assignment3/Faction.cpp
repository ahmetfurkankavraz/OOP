/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/

#include "Faction.h"

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

Faction::Faction(){ //empty constructor
    this->name = "";
    this->numberOfUnits = 0;
    this->attackPoint = 0;
    this->healthPoint = 0;
    this->unitRegenerationNumber = 0;
    this->totalHealth = 0;
    this->isAlive = true;
    this->firstEnemy = NULL;
    this->secondEnemy = NULL;
}

//constructor
Faction::Faction(string name, int numberOfUnits, int attackPoint, int healthPoint, int unitRegenerationNumber){
    this->name = name;
    this->numberOfUnits = numberOfUnits;
    this->attackPoint = attackPoint;
    this->healthPoint = healthPoint;
    this->unitRegenerationNumber = unitRegenerationNumber;
    this->totalHealth = numberOfUnits * healthPoint;
    this->isAlive = true;
    this->firstEnemy = NULL;
    this->secondEnemy = NULL;
}

// Assigning enemies according to the arrangement  (Orcs-Dwarves-Elves)
void Faction::AssignEnemies(Faction* f1, Faction* f2){
    string name1 = f1->GetName();
    
    //For Orcs, Dwarves should be first and Elves should be second enemy
    if (this->name == "Orcs"){ 
        if (name1 == "Dwarves") {
            firstEnemy = f1;
            secondEnemy = f2;
        }
        else {
            firstEnemy = f2;
            secondEnemy = f1;           
        }
    }

    //For Dwarves, Orcs should be first and Elves should be second enemy
    else if (this->name == "Dwarves"){
        if (name1 == "Orcs") {
            firstEnemy = f1;
            secondEnemy = f2;
        }
        else {
            firstEnemy = f2;
            secondEnemy = f1;           
        }
    }

    //For Elves, Orcs should be first and Dwarves should be second enemy
    else if (this->name == "Elves"){
        if (name1 == "Orcs") {
            firstEnemy = f1;
            secondEnemy = f2;
        }
        else {
            firstEnemy = f2;
            secondEnemy = f1;           
        }
    }
}

//Printing informations according to the wanted format
void Faction::Print(){
    cout << "Faction Name:         " << this->name << endl;
    if (isAlive)
        cout << "Status:               " << "Alive" << endl;
    else
        cout << "Status:               " << "Defeated" << endl;
    cout << "Number of Units:      " << this->numberOfUnits << endl;
    cout << "Attack Point:         " << this->attackPoint << endl;
    cout << "Health Point:         " << this->healthPoint << endl;
    cout << "Unit Regen Number:    " << this->unitRegenerationNumber << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}

void Faction::EndTurn(){

    //if numberOfUnits is lower than 0, assign 0.
    if (numberOfUnits < 0)
        numberOfUnits = 0;
    
    //if numberOfUnits is 0, the faction should be "defeated"
    if (numberOfUnits == 0)
        isAlive = false;

    //else, append new units
    else {
        this->numberOfUnits += this->unitRegenerationNumber;
    }
    
    this->SetTotalHealth(); //set total health
}
