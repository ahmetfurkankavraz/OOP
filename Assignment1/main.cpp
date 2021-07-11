//////////////////////////////////
/*      Ahmet Furkan Kavraz     */
/*          150190024           */
//////////////////////////////////

#include <iostream>
#include <fstream>
#include "GreatWarrior.h"
#include "GreatWarrior.cpp"

using namespace std;


void listCharacters(CharacterList&);
void listLands(CharacterList&);
void readData(string, CharacterList&);
void printGameMenu();
bool endOfTurn(Character&, int);

int main() {
    cout << "Welcome to the Great Warriors. Create your character and attack other lands to be a great warrior.\n" << endl;

    CharacterList charList;             // list object to store the characters

    string fileName = "characters.txt"; // read characters.txt file
    readData(fileName, charList);

    /* creating player's character */
    string name, land, general;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter name of your capital: ";
    cin >> land;

    cout << "Enter name of your general: ";
    cin >> general;


    Land* capital = new Land(land, "village");
    Character* character = new Character(name, 3, 20);
    character->addLand(capital);
    
    const Character* generalCharacter = new Character(general);

    Character* temp = charList.addCharacter(character);
    character = temp;

    // In-game loop 
    int choice = 0, round = 0;
    while (choice != 6) {
        printGameMenu();

        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "You have rested in your palace." << endl;
            cout << "You've talked with your general " << generalCharacter->getName() << "." << endl;

            round++;
            break;
        }
        case 2: {
            listLands(charList);
            cout << "Enter name of the land to attack." << endl;

            string land;
            cin >> land;

            string landOwner = charList.getLandOwner(land);


            //  !War time!  //
            if (landOwner != "&"){
                if (landOwner != character->getName()){
                    Character* enemy = charList.getPlayer(landOwner);
                    int enemyManpower = enemy->getManpower();
                    int charManpower = character->getManpower();

                    if (charManpower >= enemyManpower){ // Winning senario
                        character->addLand(enemy->removeLand(land));
                        character->decreaseManpower(enemyManpower);
                        if (enemy->getNumOfLands() == 0){
                            Character** charAdress = &character;
                            charList.delCharacter(enemy, charAdress);
                        }
                        cout << "You've won the battle and conquered " << land << "." << endl;
                    }
                    else { // Losing senario
                        character->decreaseManpower(charManpower);
                        cout << "You've lost the battle and " << charManpower << " manpower." << endl;
                    }
                    round++;
                }
                else {
                    cout << endl << "You can not attack your own land!" << endl;
                }
            }
            else {
                cout << "Invalid land name." << endl;
            }

            
            break;
        }
        case 3: {
            cout << "How much manpower do you need? (1 manpower=5 gold)" << endl;

            int order;
            cin >> order;


            int characterGold = character->getGold();
            if (characterGold >= order*5){  // Adding manpower
                character->appendManpower(order);
                int newManpower = character->getManpower();
                character->decreaseGold(order*5);
                cout << "Order successful. You have " << newManpower << " manpower." << endl;
            }
            else {
                cout << "You do not have enough money." << endl;
            }
            round++;
            break;
        }
        case 4:
            listCharacters(charList);
            break;
        case 5:
            listLands(charList);
            break;
        case 6:
            delete generalCharacter;
            return 0;
        default:
            cout << "You entered an invalid value. Try again." << endl;
            break;
        }


        if (choice == 3 || choice == 4 || choice == 5){ // no turn passes.
            continue;
        }

        bool flag = endOfTurn(*character, round); // End of the turn

        if (flag == true){  // //game end senario with losing
            delete generalCharacter;
            return 0;
        }
        else {  // a turn before for losing
            if (character->getNumOfLands() == 0){
                Character** charAdress = &character;
                charList.delCharacter(character, charAdress);
            }

            if (charList.getPlayerNum() == 1){ //game end senario with winning
                cout << character->getName() << " is the only great warrior now." << endl;
                delete generalCharacter;
                return 0;
            }
        }
    }
}

void readData(string fileName, CharacterList& charList) {

    fstream dataFile(fileName.c_str());

    if (dataFile.is_open()) {

        string word;
        while (dataFile >> word) {

            string name, title;
            int money, manpower, numOfLands;

            name = word;
            dataFile >> manpower;
            dataFile >> money;
            dataFile >> numOfLands;

            Character* tempCharacter = new Character(name, manpower, money);

            string landName, holding;
            for (int i = 0; i < numOfLands; i++) {
                dataFile >> landName;
                dataFile >> holding;

                Land* tempLand = new Land(landName, holding); // adding lands to the character
                tempCharacter->addLand(tempLand);
            }
            charList.addCharacter(tempCharacter); // adding characters to the character list

        }

        dataFile.close();
    }
    else cout << "Unable to open the file" << endl;

    return;
}

void printGameMenu() {
    cout << endl;
    cout << "1. Stay in your palace" << endl;
    cout << "2. Attack to a land" << endl;
    cout << "3. Buy manpower" << endl;
    cout << "4. List characters" << endl;
    cout << "5. List lands" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void listCharacters(CharacterList& charList) {
    cout << endl;
    
    for (int i = 0; i < charList.size; i++){
        cout << (charList.characters[i]).getName() << endl;
    }

}

void listLands(CharacterList& charList) {
    cout << endl;

    for (int i = 0; i < charList.size; i++){
        charList.characters[i].printLands(); // printing lands
    }
    cout << endl;
}

bool endOfTurn(Character& player, int round) { //return a bool value that indicates if the game is over or not.
   
    int landNum = player.getNumOfLands();
    if (landNum == 0){
        cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
        cout << endl;
        cout << "GAME OVER." << endl << endl;
        return true;
    }

    player.getTaxes(); // getting taxes accroding to the holding type.

    int manpower = player.getManpower();
    if (manpower == 0){
        player.removeLandRandom(); // rebellions
        cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;
    }
    else {
        int gold = player.getGold();
        if (gold < manpower){
            player.decreaseManpower(manpower-gold);
            player.decreaseGold(gold);
            cout << manpower-gold << " soldiers run away from your army because you don't have enough gold to feed them." << endl;
        }
        else {
            player.decreaseGold(manpower);
        }
    }

    //printing turn informations
    cout << "Turn " << round << ": " << " " << player.getName() << " has " << player.getNumOfLands()
        << " land(s), " << player.getManpower() << " manpower and " << player.getGold() << " golds." << endl;

    return false;
}
