#include <iostream>
#include <string>
#include <typeinfo>
#include "Helper.h"

using namespace std;

class combinatorics {
public:

	//Int
	int permutation(uint64_t input);
	int dispositions(uint64_t n, uint64_t k, bool r);
	int combinations(uint64_t n, uint64_t k, bool r);

	//String
	int permutation(string s);
};

int combinatorics::permutation(string s) { return(fact(s.length()) / intL.listFact(s)); }

int combinatorics::permutation(uint64_t n) { return(fact(n)); }

int combinatorics::dispositions(uint64_t n, uint64_t k, bool r) {
	if (r)
		return pow(n, k);
	else
		return fact(n) / fact(n - k);
}

int combinatorics::combinations(uint64_t n, uint64_t k, bool r) {
	if (r)
		return fact(n+k-1)/(fact(k)*fact(n-1));
	else
		return fact(n) / (fact(k) * fact(n - k));
}

void close() {
	cout << "\nApplication closed! \n\n";
	system("PAUSE");
}

void start() {

	combinatorics C;

	system("cls");
	cout << "1) Permutations\n";
	cout << "2) Dispositions\n";
	cout << "3) Combinations\n";
	cout << "4) Close\n\n >> ";;

	int choice;
	int n, k;
	bool r;
	cin >> choice;
	if (choice == 1) { //Permutations
		string s;
		system("cls");
		cout << "Insert a word or a number\n\n >> ";
		cin >> s;
		if (cifian(s)) {
			cout << endl << "Final Result: " << C.permutation(stoi(s));
			close();
		}
		else {
			cout << endl << "Final Result: " << C.permutation(s);
			close();
		}
	}
	else if (choice == 2) {
		system("cls");
		cout << "Insert n: ";
		cin >> n;
		cout << "Insert k: ";
		cin >> k;
		cout << "\nDo you need to consider repetitions? (1 = Yes | 0 = No) \n\n >> ";
		cin >> r;
		cout << endl << "Final Result: " << C.dispositions(n, k, r);
		close();
	}
	else if (choice == 3) {
		system("cls");
		cout << "Insert n: ";
		cin >> n;
		cout << "Insert k: ";
		cin >> k;
		cout << "\nDo you need to consider repetitions? (1 = Yes | 0 = No) \n\n >> ";
		cin >> r;
		cout << endl << "Final Result: " << C.combinations(n, k, r);
		close();
	}
	else if (choice == 4) {
		close();
	}
	else
		start();
}



int main()
{
	start();
}