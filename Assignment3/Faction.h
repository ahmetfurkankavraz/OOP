/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.05.2021
*/

#pragma once

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Faction{
protected: //protected because we will reach the variables from the other classes
    string name;
    Faction* firstEnemy;
    Faction* secondEnemy;
    int numberOfUnits;
    int attackPoint;
    int healthPoint;
    int unitRegenerationNumber;
    int totalHealth;
    bool isAlive;

public:
    //functions that we need to implement
    Faction();
    Faction(string, int, int, int, int);
    void AssignEnemies(Faction*, Faction*);
    // pure virtual functions, they will be defined in child classes
    virtual void PerformAttack() =0;
    virtual void ReceiveAttack(string, int, int) =0;
    virtual int PurchaseWeapons(int) =0;
    virtual int PurchaseArmors(int) =0;
    virtual void Print();
    void EndTurn();
    
    //getters and setters
    bool IsAlive(){return this->isAlive;}
    string GetName(){return this->name;}
    int GetNumberOfUnits(){return this->numberOfUnits;}
    int GetAttackPoint(){return this->attackPoint;}
    int GetHealthPoint(){return this->healthPoint;}
    int GetUnitRegenerationNumber(){return this->unitRegenerationNumber;}
    int GetTotalHealth(){return this->totalHealth;}
    void SetName(string name){this->name = name;}
    void SetNumberOfUnits(int numberOfUnits){this->numberOfUnits = numberOfUnits;}
    void SetAttackPoint(int attackPoint){this->attackPoint = attackPoint;}
    void SetHealthPoint(int healthPoint){this->healthPoint = healthPoint;}
    void SetUnitRegenerationNumber(int unitRegenerationNumber){this->unitRegenerationNumber = unitRegenerationNumber;}
    void SetTotalHealth(){this->totalHealth = this->numberOfUnits * this->healthPoint;}
};