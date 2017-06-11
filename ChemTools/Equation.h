#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "Element.h"
#include "Term.h"

using namespace std;
using namespace boost;

class Equation
{
public:


	Equation(map<string, Element> periodicTable, const string& rawEq);
	~Equation();

	static map<string, Element> elementParse(const string& fileName);

	void printPreAmt(double proAmt);
	void split(const string& s, char delim, vector<string>& result);


public:
	vector<Term> precursor;
	vector<Term> product;
};

