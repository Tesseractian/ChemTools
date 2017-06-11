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
	vector<pair<Element, int> > cmpd;
	string formula;

private:
	int extractNumber(const string& rawTerm, int& cursor);
	vector<pair<Element, int> > extractCompound(map<string, Element>& periodicTable, const string& rawTerm, int& cursor);
	string extractElementSym(const string& rawTerm, int& cursor);
	int extractSubscript(const string& rawTerm, int& cursor);

};

