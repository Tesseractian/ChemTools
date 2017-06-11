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
	
	string s;
	cin >> s;
	double input;	//desired mass of first compound of the products
	cin >> input;

	Equation eq(periodicTable, s);
	eq.printPreAmt(input);

	return 0;
}