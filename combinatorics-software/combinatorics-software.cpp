#include <iostream>
#include <string.h>
#include <typeinfo>
#include "Helper.h"
#include "linked-list.h"

using namespace std;

class combinatorics {
public:


	int binomialFactor(int n);
	int binomialFactor(int n, int k);

	//Int
	int permutation(int input);
	int dispositions(int input, bool r);
	int combinations(int input, bool r);

	//String
	int permutation(string s);
	int dispositions(string s, bool r);
	int combinantions(string s, bool r);

};

int combinatorics::binomialFactor(int n) {
	return 0;
}

int combinatorics::permutation(int input) {
	return 0;
}

int combinatorics::permutation(string s) {
	return(fact(s.length()) / intL.listFact(s));
}

int main()
{
	combinatorics C;
	cout << C.permutation("god");
}