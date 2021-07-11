//////////////////////////////////
/*      Ahmet Furkan Kavraz     */
/*          150190024           */
//////////////////////////////////


#pragma once

using namespace std;

#define ARRAY_LENGTH 0

class Land{
    string name;
    string holding;
    Land* next;
    public:
        //constructor - destructor
        Land(string, string);
        Land(Land &);

        // necessary inline functions
        string getHoldingType(){return holding;}
        Land* getNext(){return this->next;}
        void changeNext(Land* next){this->next = next;}
        string getName(){return this->name;}
};

class Character{
    string name;
    int manpower;
    int gold;
    int numOfLands;
    Land* lands;
    public:
        //constructor - destructor
        Character(string, int, int);
        Character(string);
        Character();
        Character(Character &);
        ~Character();

        // necessary functions as in the question
        void getTaxes();
        void addLand(Land *A);
        Land* removeLand(string);
        void removeLandRandom();
        void printLands();
        bool searchLand(string landName);

        // necessary inline functions
        string getName() const{return name; }
        string getName(){return name; }
        int getGold(){return gold;}
        void decreaseGold(int g){this->gold -= g;};
        int getManpower(){return manpower;}
        void appendManpower(int m){this->manpower += m;}
        void decreaseManpower(int m){this->manpower -= m;}
        int getNumOfLands(){return this->numOfLands;}
        Land *getLandsHead(){return this->lands;}
        void setLandsHead(Land* lands){this->lands = lands;}
};

class CharacterList{
    friend void listCharacters(CharacterList&);
    friend void listLands(CharacterList&);
    Character* characters;
    int size;
    int maxSize;
    public:
        //constructor - destructor
        CharacterList();
        ~CharacterList();

        //necessary functions
        Character* addCharacter(Character*);
        void delCharacter(Character*, Character**);
        Character* getPlayer(string);
        string getLandOwner(string );
        int getPlayerNum(){return size;}
};