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

class Elves : public Faction { //inheritence

public:
    // necessary functions
    Elves();
    Elves(string, int, int, int, int);
    void PerformAttack();
    void ReceiveAttack(string, int, int);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};