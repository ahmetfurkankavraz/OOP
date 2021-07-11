/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/


#include "Faction.h"
#include "Dwarves.h"

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;    


Dwarves::Dwarves() : Faction(){ //empty constructor

}

//constructor
Dwarves::Dwarves(string name, int numberOfUnits, int attackPoint, int healthPoint, int unitRegenerationNumber) 
    : Faction(name, numberOfUnits, attackPoint, healthPoint, unitRegenerationNumber){

}

//performing attacks according to given informations
void Dwarves::PerformAttack(){
    if (firstEnemy->IsAlive() && secondEnemy->IsAlive()){

        //attacking to Orcs with %50 of units
        firstEnemy->ReceiveAttack(this->name, this->numberOfUnits/2, this->attackPoint );
        
        //attacking to Elves with %50 of units
        secondEnemy->ReceiveAttack(this->name, this->numberOfUnits/2, this->attackPoint );
    }

    //if just Orcs are living, attack with all units
    else if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack(this->name, this->numberOfUnits, this->attackPoint );
    }

    //if just Elves are living, attack with all units
    else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        secondEnemy->ReceiveAttack(this->name, this->numberOfUnits, this->attackPoint );
    }
}

// attack coming from Orcs and Elves
void Dwarves::ReceiveAttack(string name, int numberOfUnits, int attackPoint){
    this->numberOfUnits -= (numberOfUnits*attackPoint) / this->healthPoint;
}


int Dwarves::PurchaseWeapons(int num){
    this->attackPoint += num; //attack point should sum with num
    return 10*num; //10 gold for each weapon
}


int Dwarves::PurchaseArmors(int num){
    this->healthPoint += 2*num; //health point should sum with double of num
    return 3*num; //3 gold for each armor
}

// printing necessary information
void Dwarves::Print(){
    cout << '"' << "Taste the power of our axes!" << '"'<< endl;
    Faction::Print(); //parent class function called
}