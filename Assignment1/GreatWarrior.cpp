//////////////////////////////////
/*      Ahmet Furkan Kavraz     */
/*          150190024           */
//////////////////////////////////


#include <iostream>
#include "GreatWarrior.h"

using namespace std;

#define ARRAY_LENGTH 0


// Land Functions
// Constructors
Land::Land(string name, string holding){
    this->name = name;
    this->holding = holding;
    this->changeNext(NULL);
}
Land::Land(Land &A){
    this->name = A.name;
    this->holding = A.holding;
    this->changeNext(A.getNext());
}


// Character Functions
// Constructors and Destructor
Character::Character(string name, int manpower, int gold){
    this->name = name;
    this->manpower = manpower;
    this->gold = gold;
    this->numOfLands = 0;
    this->lands = NULL;
}
Character::Character(string name){
    this->name = name;
    this->manpower = 0;
    this->gold = 0;
    this->numOfLands = 0;
    this->lands = NULL;
}
Character::Character(){
    this->name = "";
    this->manpower = 0;
    this->gold = 0;
    this->numOfLands = 0;
    this->lands = NULL;
}
Character::Character(Character &A){
    this->name = A.name;
    this->manpower = A.manpower;
    this->gold = A.gold;
    this->numOfLands = A.numOfLands;

    Land* traverse = lands;
    while (traverse){
        Land* temp = new Land(*traverse);
        this->addLand(temp);
        traverse = traverse->getNext();
    }
}
Character::~Character(){

    Land* traverse = lands;

    while(traverse){
        Land* temp = traverse;
        traverse = traverse->getNext();
        delete temp;
    }

}
// Implementation of necessary functions
void Character::getTaxes(){
    Land* traverse = lands;
    int totalTax = 0;
    while (traverse){
        string type = traverse->getHoldingType();
        if (type == "village"){
            totalTax += 5;
        }
        else if (type == "castle"){
            totalTax += 7;
        }
        else if (type == "city"){
            totalTax += 10;
        }
        traverse = traverse->getNext();
    }
    gold += totalTax;
    return;
}
void Character::addLand(Land* A){
    if (lands == NULL){
        lands = A;
    }
    else{
        Land* temp = lands->getNext(); // adding the land to place just after the head
        lands->changeNext(A);
        A->changeNext(temp);
    }
    numOfLands++;
}
Land* Character::removeLand(string name){
    
    Land* temp;
    numOfLands--;

    if (lands->getName() == name){ // in head
        temp = lands;
        lands = lands->getNext();
        temp->changeNext(NULL);
        return temp;
    }
    else { // after head
        Land* traverse = lands;
        while (traverse->getNext() && traverse->getNext()->getName() != name){ //finding correct place
            traverse = traverse->getNext();
        }
        if (traverse->getNext()->getName() == name){ //removing
            temp = traverse->getNext();
            traverse->changeNext(temp->getNext());
            temp->changeNext(NULL);
            return temp;
        }
    }
    return NULL;
}
void Character::removeLandRandom(){

    numOfLands--;
    if (numOfLands == 0){ // corner case
        delete lands;
        lands = NULL;
        return;
    }
    Land* traverse = lands;
    if (traverse != NULL){ // deleting the last element of the linked list
        Land* temp = NULL;
        while (traverse->getNext()){ 
            temp = traverse;
            traverse = traverse->getNext();
        }
        if (temp != NULL){
            temp->changeNext(NULL);
            delete traverse;
        }
        else {
            delete traverse;
            lands = NULL;
        }
    }
    
}
void Character::printLands(){
    
    Land* traverse = lands;
    while (traverse){
        cout << traverse->getName() << " " << traverse->getHoldingType() << " owned by " << name << endl;
        traverse = traverse->getNext();
    }
    return;

}
bool Character::searchLand(string landName){ // has character that land?
    Land* traverse = lands;
    bool flag = false;
    while (traverse){
        if (traverse->getName() == landName)
            flag = true;
        traverse = traverse->getNext();
    }
    return flag;
}


// CharacterList Functions
// Constructor - Destructor
CharacterList::CharacterList(){
    size = 0;
    maxSize = ARRAY_LENGTH;
    characters = new Character [maxSize];
}
CharacterList::~CharacterList(){
    delete [] characters;
    size = 0;
    maxSize = 0;
}
Character* CharacterList::addCharacter(Character* character){

    // incrementing the list size one by one (at the first the size = 0)
    if (size+1 >= maxSize){
        maxSize += 1;
        
        Character* charactersNew = new Character [maxSize];
        
        for (int i = 0; i < size; i++){
            charactersNew[i] = characters[i];
            characters[i].setLandsHead(NULL);
        }
        Character* temp = characters;
        characters = charactersNew;
        delete [] temp;
    }

    // appending the character to the list
    characters[size] = *character;
    character->setLandsHead(NULL);
    
    delete character;
    size++;

    return &(characters[size-1]);
}
void CharacterList::delCharacter(Character* enemy, Character** charAdress){

    // removing the character from the array
    int index = 0;
    for ( ; index < size; index++){
        if (enemy->getName() == (&characters[index])->getName()){
            break;
        } 
    }
    if (*charAdress == enemy){ // deleting character from the array at the end of the game.
        characters[index] = characters[size-1];
        Character A;
        characters[size-1] = A;
        size--;
    }
    else {
        if (index < size){
            characters[index] = characters[size-1];
            if (*charAdress == &characters[size-1]){ //changing our character value which we define in main function
                *charAdress = &characters[index];
            }
            Character A;
            characters[size-1] = A;
            size--;
        }
    }
    return;
}
Character* CharacterList::getPlayer(string name){ // returning the pointer of the character
    for (int i = 0; i < size; i++){
        if (name == characters[i].getName()){
            return (characters+i);
        }
    }
    return NULL;
}
string CharacterList::getLandOwner(string landName){ // returning the name of the LandOwner
    for (int i = 0; i < size; i++){
        if (characters[i].searchLand(landName) == true){
            return characters[i].getName();
        }
    }
    return "&";
}