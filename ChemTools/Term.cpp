#include "Term.h"



Term::Term()
{
}

Term::Term(map<string, Element> periodicTable, const string& rawTerm)
{
	int cursor = 0;
	double num = extractNumber(rawTerm, cursor);	//coefficient
	formula = rawTerm.substr(cursor);
	vector<pair<Element, double> > temp = extractCompound(periodicTable, rawTerm, cursor);	//current compound
	for (int i = 0; i < temp.size(); ++i) {
		cmpd.push_back(make_pair(temp[i].first, temp[i].second * num));
	}

}

Term::~Term()
{
}

double Term::getAMU() const
{
	double total = 0;
	for (int i = 0; i < cmpd.size(); ++i) {
		total += cmpd[i].first.amu * cmpd[i].second;
	}
	return total;
}

double Term::extractNumber(const string& rawTerm, int& cursor) {
	int numerator = 0;
	int denominator = 0;
	bool isNumerator = true;
	for (; cursor < rawTerm.size(); ++cursor) {
		if (rawTerm[cursor] >= '0' && rawTerm[cursor] <= '9') {
			if (isNumerator) {
				numerator = numerator * 10 + (rawTerm[cursor] - '0');
			}
			else {
				denominator = denominator * 10 + (rawTerm[cursor] - '0');
			}
		}
		else if (rawTerm[cursor] == '/') {
			isNumerator = false;
		}
		else {
			break;
		}
	}

	return (denominator == 0) ? ((numerator == 0) ? 1 : numerator)  : (numerator / (double) denominator);
}

vector<pair<Element, double> > Term::extractCompound(map<string, Element>& periodicTable, const string& rawTerm, int& cursor) {
	map<string, double> compound;
	
	while (cursor < rawTerm.size()) {
		string sym = extractElementSym(rawTerm, cursor);
		double subscript = extractSubscript(rawTerm, cursor);
		if (compound.find(sym) == compound.end()) {
			compound[sym] = subscript;
		}
		else {
			compound[sym] += subscript;
		}
		//cursor does not need incrementation
	}

	vector<pair<Element, double> > compoundVec;
	for (auto it = compound.begin(); it != compound.end(); ++it) {
		compoundVec.push_back(make_pair(periodicTable[it->first], it->second));
	}
	return compoundVec;
}

string Term::extractElementSym(const string& rawTerm, int& cursor) {
	string sym;
	sym += rawTerm[cursor++];
	for (; cursor < rawTerm.size() && 'a' <= rawTerm[cursor] && rawTerm[cursor] <= 'z'; ++cursor) {
		sym += rawTerm[cursor];
	}
	return sym;
}


double Term::extractSubscript(const string & rawTerm, int & cursor)
{
	double number = 1;	//subscript value
	if (cursor < rawTerm.size() && rawTerm[cursor] == '_') {
		++cursor;
		if (rawTerm[cursor] == '{') {
			cursor++;
			number = extractNumber(rawTerm, cursor);
		}
		else {
			number = rawTerm[cursor] - '0';
		}
		++cursor;
	}
	return number;
}