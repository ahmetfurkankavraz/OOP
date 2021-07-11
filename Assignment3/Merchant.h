/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/

#pragma once

#include "Faction.h"

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Merchant{ //variables of merchant
    Faction* firstFaction;
    Faction* secondFaction;
    Faction* thirdFaction;
    int startingWeaponPoint;
    int startingArmorPoint;
    int revenue;
    int weaponPoint;
    int armorPoint;

public:
    //functions that we need to implement
    Merchant();
    Merchant(int, int);
    void AssignFactions(Faction*,Faction*,Faction*);
    bool SellWeapons(string, int);
    bool SellArmors(string, int);
    void EndTurn();

    //getters and setters
    int GetRevenue(){return this->revenue;}
    int GetWeaponPoints(){return this->weaponPoint;}
    int GetArmorPoints(){return this->armorPoint;}
    void SetRevenue(int revenue){this->revenue = revenue;}
    void SetWeaponPoints(int weaponPoint){this->weaponPoint = weaponPoint;}
    void SetArmorPoints(int armorPoint){this->armorPoint = armorPoint;}
};