#pragma once

#include <string>

using namespace std;

class Element
{
public:
	Element() {
		amu = 0;
	}

	Element(int aNum, string sym, string name, double amu) : aNum(aNum), sym(sym), name(name), amu(amu) {}

	string toString() const {
		return "[ " + to_string(aNum) + ", " + sym + ", " + name + ", " + to_string(amu) + " ]";
	}

public:
	int aNum;
	string sym;
	string name;
	double amu;

};

