/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/

#include "Faction.h"
#include "Elves.h"

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;    


Elves::Elves() : Faction(){ //empty constructor

}

//constructor
Elves::Elves(string name, int numberOfUnits, int attackPoint, int healthPoint, int unitRegenerationNumber) 
    : Faction(name, numberOfUnits, attackPoint, healthPoint, unitRegenerationNumber){

}

//performing attacks according to given informations
void Elves::PerformAttack(){

    //if both enemy alive
    if (firstEnemy->IsAlive() && secondEnemy->IsAlive()){

        //attacking to Orcs with %60 of units
        firstEnemy->ReceiveAttack(this->name, this->numberOfUnits*3/5, this->attackPoint );
        
        //attacking to Dwarves with remain of units
        //attack point increased %150 when attacking Dwarves
        secondEnemy->ReceiveAttack(this->name, this->numberOfUnits - this->numberOfUnits*3/5, this->attackPoint*3/2 );
    }

    //if just Orcs are living, attack with all units
    else if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack(this->name, this->numberOfUnits, this->attackPoint );
    }

    //if just Dwarves are living attack with all units
    else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        //attack point increased %150 when attacking Dwarves
        secondEnemy->ReceiveAttack(this->name, this->numberOfUnits, this->attackPoint*3/2 ); 
    }
}


void Elves::ReceiveAttack(string name, int numberOfUnits, int attackPoint){
    
    // attack coming from Orcs should increased to %125
    if (name == "Orcs"){
        this->numberOfUnits -= (numberOfUnits*attackPoint*5/4) / this->healthPoint;
    }
    
    // attack coming from Dwarves should reduced to %75
    else if (name == "Dwarves"){
        this->numberOfUnits -= (numberOfUnits*attackPoint*3/4) / this->healthPoint;
    }
}


int Elves::PurchaseWeapons(int num){
    this->attackPoint += 2*num; //attack point should sum with double num 
    return 15*num; //15 gold for each weapon
}


int Elves::PurchaseArmors(int num){
    this->healthPoint += 4*num; //health point should sum with quadrupled of num 
    return 5*num; //5 gold for each armor
}

// printing necessary information
void Elves::Print(){
    cout << '"'<< "You cannot reach our elegance." << '"'<< endl;
    Faction::Print(); //parent class function called
}