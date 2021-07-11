/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/

#include "Faction.h"
#include "Orcs.h"

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;    


Orcs::Orcs() : Faction(){ //empty constructor

}

//constructor
Orcs::Orcs(string name, int numberOfUnits, int attackPoint, int healthPoint, int unitRegenerationNumber) 
    : Faction(name, numberOfUnits, attackPoint, healthPoint, unitRegenerationNumber){

}

//performing attacks according to given informations
void Orcs::PerformAttack(){

    //if both enemy alive
    if (firstEnemy->IsAlive() && secondEnemy->IsAlive()){

        //attacking to Dwarves with remain of units
        firstEnemy->ReceiveAttack(this->name, this->numberOfUnits - this->numberOfUnits*7/10, this->attackPoint ); 
        
        //attacking to Elves with %70 of units
        secondEnemy->ReceiveAttack(this->name, this->numberOfUnits*7/10, this->attackPoint );
    }

    //if just Dwarves are living, attack with all units
    else if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack(this->name, this->numberOfUnits, this->attackPoint );
    }

    //if just Elves are living attack with all units
    else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        secondEnemy->ReceiveAttack(this->name, this->numberOfUnits, this->attackPoint );
    }
}


void Orcs::ReceiveAttack(string name, int numberOfUnits, int attackPoint){
    
    // attack coming from Elves should reduced to %75
    if (name == "Elves"){
        this->numberOfUnits -= (numberOfUnits*attackPoint*3/4) / this->healthPoint;
    }

    // attack coming from Dwarves should reduced to %80
    else if (name == "Dwarves"){
        this->numberOfUnits -= (numberOfUnits*attackPoint*4/5) / this->healthPoint;
    }
}


int Orcs::PurchaseWeapons(int num){
    this->attackPoint += 2*num; //attack point should sum with double of num
    return 20*num; //20 gold for each weapon
}


int Orcs::PurchaseArmors(int num){
    this->healthPoint += 3*num; //health point should sum with triple of num
    return num; //1 gold for each armor
}

// printing necessary information
void Orcs::Print(){
    cout << '"'<< "Stop running, you'll only die tired!" << '"'<< endl;
    Faction::Print(); //parent class function called
}