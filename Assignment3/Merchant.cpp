/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/

#include "Faction.h"
#include "Merchant.h"

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;


Merchant::Merchant(){ //empty constructor
    this->firstFaction = NULL;
    this->secondFaction = NULL;
    this->thirdFaction = NULL;
    this->startingWeaponPoint = 0;
    this->startingArmorPoint = 0;
    this->revenue = 0;
    this->weaponPoint = 0;
    this->armorPoint = 0;
}

//constructor
Merchant::Merchant(int wp, int ap){
    this->firstFaction = NULL;
    this->secondFaction = NULL;
    this->thirdFaction = NULL;
    this->startingWeaponPoint = wp;
    this->startingArmorPoint = ap;
    this->revenue = 0;
    this->weaponPoint = startingWeaponPoint;
    this->armorPoint = startingArmorPoint;
}

// Assigning factions according to the arrangement  (Orcs-Dwarves-Elves)
void Merchant::AssignFactions(Faction* ff, Faction* sf, Faction* tf){

    // Finding Orcs and assigning it to the firstFaction
    if (ff->GetName() == "Orcs"){ 
        this->firstFaction = ff;
    } else if (sf->GetName() == "Orcs"){
        this->firstFaction = sf;
    }else if (tf->GetName() == "Orcs"){
        this->firstFaction = tf;
    }

    // Finding Dwarves and assigning it to the secondFaction
    if (ff->GetName() == "Dwarves"){
        this->secondFaction = ff;
    } else if (sf->GetName() == "Dwarves"){
        this->secondFaction = sf;
    } else if (tf->GetName() == "Dwarves"){
        this->secondFaction = tf;
    } 

    // Finding Elves and assigning it to the thirdFaction
    if (ff->GetName() == "Elves"){
        this->thirdFaction = ff;
    } else if (sf->GetName() == "Elves"){
        this->thirdFaction = sf;
    } else if (tf->GetName() == "Elves"){
        this->thirdFaction = tf;
    } 
}


bool Merchant::SellWeapons(string name, int weaponPoints){

    if (weaponPoints <= 0){ // exit case
        return false;
    }
    else {    
        //finding true faction for sellWeapons
        Faction* faction;
        if (name == firstFaction->GetName()) 
            faction = firstFaction;
        else if (name == secondFaction->GetName()) 
            faction = secondFaction;
        else if (name == thirdFaction->GetName()) 
            faction = thirdFaction;

        //if faction is defeated
        if (!faction->IsAlive()){ 
            cout << "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        else {
            //more weapons than merchant have
            if (this->weaponPoint < weaponPoints){
                cout << "You try to sell more weapons than you have in possession." << endl;
                return false;
            }
            //assigning revenue and weaponPoint
            this->weaponPoint -= weaponPoints;
            this->revenue += faction->PurchaseWeapons(weaponPoints);
            cout << "Weapons sold!" << endl;
            return true;
        }
    }
}
bool Merchant::SellArmors(string name, int armorPoints){
    
    if (armorPoints <= 0){  // exit case
        return false;
    }
    else {
        //finding true faction for sellWeapons
        Faction* faction;
        if (name == firstFaction->GetName()) 
            faction = firstFaction;
        else if (name == secondFaction->GetName()) 
            faction = secondFaction;
        else if (name == thirdFaction->GetName()) 
            faction = thirdFaction;

        //if faction is defeated
        if (!faction->IsAlive()){
            cout << "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        else {
            //more armors than merchant have
            if (this->armorPoint < armorPoints){
                cout << "You try to sell more armors than you have in possession." << endl;
                return false;
            }
            //assigning revenue and armorPoint
            this->armorPoint -= armorPoints;
            this->revenue += faction->PurchaseArmors(armorPoints);
            cout << "Armors sold!" << endl;
            return true;
        }
    }
}

// adding new weapons and armors at the end of the turn
void Merchant::EndTurn(){
    this->weaponPoint = startingWeaponPoint;
    this->armorPoint = startingArmorPoint;
}