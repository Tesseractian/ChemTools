#include "Equation.h"



Equation::Equation(map<string, Element> periodicTable, const string& rawEq)
{
	/*
	precursor.resize(2);
	product.resize(1);

	precursor[0].cmpd.push_back(make_pair(periodicTable["H"], 4));
	precursor[1].cmpd.push_back(make_pair(periodicTable["O"], 2));

	product[0].cmpd.push_back(make_pair(periodicTable["H"], 4));
	product[0].cmpd.push_back(make_pair(periodicTable["O"], 2));
	*/

	
	int index = rawEq.find("->");
	string precursorStr = rawEq.substr(0, index);
	string productStr = rawEq.substr(index + 2);

	
	vector<string> precursorVec;	//Contains strings not Term
	vector<string> productVec;
	
	string delimiters("+");
	split(precursorStr, '+', precursorVec);
	split(productStr, '+', productVec);
	
	precursor.resize(precursorVec.size());
	product.resize(productVec.size());

	for (int i = 0; i < precursorVec.size(); ++i) {
		precursor[i] = Term(periodicTable, precursorVec[i]);
	}
	for (int i = 0; i < productVec.size(); ++i) {
		product[i] = Term(periodicTable, productVec[i]);
	}
}


Equation::~Equation()
{
}

map<string, Element> Equation::elementParse(const string& fileName) {
	map<string, Element> periodicTable;

	ifstream in(fileName);
	string line;
	getline(in, line);	//throw away 1st row
	while (!in.eof()) {
		vector<string> vec;	//parsed line
		getline(in, line);
		tokenizer<escaped_list_separator<char> > tk(line, escaped_list_separator<char>('\\', ',', '\"'));
		for (auto i = tk.begin(); i != tk.end(); ++i) {
			vec.push_back(*i);
		}

		periodicTable[vec[1]] = Element(stod(vec[0]), vec[1], vec[2], stod(vec[6]));
	}

	return periodicTable;
}

void Equation::printPreAmt(double proAmt)
{
	for (int i = 0; i < precursor.size(); ++i) {
		cout << precursor[i].formula << "\t" << proAmt / product[0].getAMU() * precursor[i].getAMU() << endl;
	}

}

void Equation::split(const string& s, char delim, vector<string>& result) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		result.push_back(item);
	}
}