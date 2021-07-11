/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 29.04.2021
*/

#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Person{
    protected:
        string name;
        string surname;
    public:
        Person(string, string);
        string getName(){return this->name;}
        void setName(string name){this->name = name;}
        string getSurname(){return this->surname;}
        void setSurname(string surname){this->surname = surname;}
};

class Passenger : public Person {
    int cash;
    bool ticket = false;
    Passenger* next = NULL;
    public:
        Passenger(string, string, int);
        Passenger(string, string);
        void buyTicket(int );
        bool getTicket(){ return this->ticket;}
        int getCash(){ return this->cash;}
        void setCash(int cash){ this->cash = cash;}
        Passenger* getNext(){return this->next;}
        void setNext(Passenger* next){this->next = next;}
};

class Astronaut : public Person {
    int numMissions;
    Astronaut* next = NULL;
    public:
        Astronaut(string, string, int);
        Astronaut(string, string);
        void completeMission();
        int getNumMissions(){return this->numMissions;}
        void setNumMissions(int numMissions){this->numMissions = numMissions;}
        Astronaut* getNext(){return this->next;}
        void setNext(Astronaut* next){this->next = next;}
};