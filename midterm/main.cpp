/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 26.04.2021
*/

#include <bits/stdc++.h>


using namespace std;

class Player {
    //private data
    string name;
    int gameScore;

public:

    // Constructor of Player
    Player(string name, int gameScore ){
        this->name = name;
        this->gameScore = gameScore;
        cout << "constructor of player" << endl;
    }

    // Printing the base class information
    void print() const{
        cout << "Name: " << this->name << " score: " << this->gameScore << endl;
    }

    // Summing the Game Score values
    int operator+(Player& p1) const {
        return this->gameScore + p1.gameScore;
    }
};

class ExpertPlayer : public Player { // inheritance
    //private data
    string skills;

public:

    // Constructor of Expert Player
    ExpertPlayer(string name, int gameScore, string skills)
                                    : Player(name,gameScore){
        this->skills = skills;
        cout << "constructor of expert player" << endl;
    }

    // Printing the class information
    void print() const{
        Player::print();
        cout << "skill: " << this->skills << endl;
    }
};

int main(){
	ExpertPlayer e1 = ExpertPlayer("ExpertPlayer 1", 10, "time");
	ExpertPlayer e2 = ExpertPlayer("ExpertPlayer 2", 30, "space");
	const Player p1 = Player("player 1", 40);
	e1.print();
	e2.print();
	p1.print();
	int sum = e1 + e2;
	cout << sum << endl;


    return 0;
}
