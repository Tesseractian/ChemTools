#pragma once

#include <vector>
#include <string>
#include <utility>
#include <map>
#include <boost/algorithm/string.hpp>

#include "Element.h"

using namespace std;

class Term
{
public:

	Term();
	Term(map<string, Element> periodicTable, const string& rawTerm);
	~Term();

	double getAMU() const;

public:
	vector<pair<Element, double> > cmpd;
	string formula;

private:
	double extractNumber(const string& rawTerm, int& cursor);
	vector<pair<Element, double> > extractCompound(map<string, Element>& periodicTable, const string& rawTerm, int& cursor);
	string extractElementSym(const string& rawTerm, int& cursor);
	double extractSubscript(const string& rawTerm, int& cursor);

};

