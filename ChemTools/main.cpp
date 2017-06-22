#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "Element.h"
#include "Equation.h"

using namespace std;




int main() {
	map<string, Element> periodicTable = Equation::elementParse("chemical_elements.csv");
	
	cout << "Enter chemical equation: " << endl;
	string s;
	cin >> s;
	cout << "Enter mass in grams of 1st term of output: " << endl;
	double input;	//desired mass of first compound of the products
	cin >> input;

	cout << endl;
	cout << "Mass of each precursor, ignore coefficients: " << endl;
	Equation eq(periodicTable, s);
	eq.printPreAmt(input);
	cout << endl;

	return 0;
}