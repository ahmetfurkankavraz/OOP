/*@AuthorStudent
Name: Ahmet Furkan Kavraz
Student ID: 150190024
Date: 23.06.2021
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Warlord {
private:
	int power;
	int magic;
public:

	/* Constructor */
	Warlord(){
		power = 0;
		magic = 0;
		throw "A warlord cannot be a non-magic wielder!";
	}
	/* Constructor with parameter*/
	Warlord(int p, int m){
		power = p;
		magic = m;
		if (p < 0) throw "A warlord cannot have negative power!";
		if (m <= 0) throw "A warlord cannot be a non-magic wielder!";
	}

	/* Printing class information*/
	void Print(){
		cout << "Power: " << power << " Magic: "<< magic << endl;
	}

	// Getter Methods
	int getpower(){
		return power;
	}
	int getmagic(){
		return magic;
	}
	
	// Operator> is used in comparision function.
	// Calculation is done due to the given criteria which is the sum of magic and power numbers
	bool operator>(Warlord second){
		int sumfirst =  this->getpower() + this->getmagic();
		int sumsecond =  second.getpower() + second.getmagic();
		return sumfirst > sumsecond;
	}
};

/* Write a comparison function which will return true if first parameter is bigger than the second */
template <typename T>
bool comparision(T a, T b){
	return a > b;
}


/* Define an STL container (vector, list, etc.) here. Use typedef to name it as "Container" */
typedef vector<Warlord> Container ;
typedef Container::iterator Iterator;

/* You should not change or remove the given code parts. Add necessary codes to get the same result with sample output */
int main() {

	try {
		Warlord w1(1, 1);
		Warlord w2(2, 2);
		Warlord w3(2, 1);

		/* Initialize the "Container" and put the w1,w2, and w3 into container */
		Container lords;
		lords.push_back(w1);
		lords.push_back(w2);
		lords.push_back(w3);
		
		cout << "Unsorted Warlords" << endl;
		for (Iterator i = lords.begin(); i != lords.end(); i++) (*i).Print();

		/* Sort Warlords in the container */
		sort(lords.begin(), lords.end(), comparision<Warlord>);

		cout << endl << "Sorted Warlords" << endl;
		for (Iterator i = lords.begin(); i != lords.end(); i++) (*i).Print();

		Warlord w4; /* by default warlords have zero power and zero magic*/
		w4.Print();
	}
	catch (const char * error){ // catching first error message
		cout << error << endl;
	}

	return 0;
}


