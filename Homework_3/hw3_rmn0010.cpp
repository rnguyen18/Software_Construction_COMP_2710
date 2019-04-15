//Ryan Nguyen
//rmn0010
//hw3_rmn0010.cpp
//The program uses randomness to solve a puzzle which is a duel to the death!
//I received no help for this project other than the Homework 3 guidelines.

#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<ctime>

using namespace std;

void test_at_least_two_alive(void);
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& B_alive, bool& C_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);

int main() 
{
	cout << "*** Welcome to the Duel Simulator ***" << fixed << endl;

	srand(time(0));
	
	test_at_least_two_alive();
	cout.precision(2);
	cout << "Press Enter to continue...";
	cin.get();

	int A = 0;
	int B = 0;
	int C = 0;

	cout << "Ready to test strategy 1 (run 10000 times):" << endl;
	cout << "Press Enter to continue...";
	cin.get();

	for (int i = 0; i < 10000; i++) {
		bool A_alive = true;
		bool B_alive = true;
		bool C_alive = true;	
		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) {
				Aaron_shoots1(B_alive, C_alive);
			}
			if (at_least_two_alive(A_alive, B_alive, C_alive) && B_alive) {
				Bob_shoots(A_alive, C_alive);
			}
			if (at_least_two_alive(A_alive, B_alive, C_alive) && C_alive) {
				Charlie_shoots(A_alive, B_alive);
			}
		}

		if (A_alive) {
			A++;
		}
		if (B_alive) {
			B++;
		}
		if (C_alive) {
			C++;
		}
	}

	cout << "Aaron won " << A << "/10000 duels or " << ((double) A/100.0) << "%" << endl;
	cout << "Bob won " << B << "/10000 duels or " << ((double) B/100.0) << "%" << endl;
	cout << "Charlie won " << C << "/10000 duels or " << ((double) C/100.0) << "%" << endl << endl;

	cout << "Ready to test strategy 2 (run 10000 times):" << endl;
	cout << "Press Enter to continue...";
	cin.get();

	A = 0;
	B = 0;
	C = 0;

	for (int i = 0; i < 10000; i++) {
		bool A_alive = true;
		bool B_alive = true;
		bool C_alive = true;
		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) {
				Aaron_shoots2(B_alive, C_alive);
			}
			if (at_least_two_alive(A_alive, B_alive, C_alive) && B_alive) {
				Bob_shoots(A_alive, C_alive);
			}
			if (at_least_two_alive(A_alive, B_alive, C_alive) && C_alive) {
				Charlie_shoots(A_alive, B_alive);
			}
		}

		if (A_alive) {
			A++;
		}
		if (B_alive) {
			B++;
		}
		if (C_alive) {
			C++;
		}
	}

	cout << "Aaron won " << A << "/10000 duels or " << ((double) A/100.0) << "%" << endl;
	cout << "Bob won " << B << "/10000 duels or " << ((double) B/100.0) << "%" << endl;
	cout << "Charlie won " << C << "/10000 duels or " << ((double) C/100.0) << "%" << endl << endl;
	cout << "Strategy 2 is better than strategy 1." << endl;
}

void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";

	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";

}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
	if (A_alive) {
		if (B_alive) {
			return true;
		}
		if (C_alive) {
			return true;
		}
	}
	if (B_alive && C_alive) {
		return true;
	}
	
	return false;
}

void Aaron_shoots1(bool& B_alive, bool& C_alive)
{
	int shot_results = rand()%100;
	
	if (shot_results <= 33) {
		if (C_alive) {
			C_alive = false;
		} else {
			B_alive = false;
		}
	}
}

void Bob_shoots(bool& A_alive, bool& C_alive)
{
	int shot_results = rand()%100;
	
	if (shot_results <= 50) {
		if (C_alive) {
			C_alive = false;
		} else {
			A_alive = false;
		}
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive)
{
	if (B_alive) {
		B_alive = false;
	} else {
		A_alive = false;
	}
}

void Aaron_shoots2(bool& B_alive, bool& C_alive)
{
	if ((B_alive && C_alive) == false) {
		int shot_results = rand()%100;
		
		if (shot_results <= 33) {
			if (C_alive) {
				C_alive = false;
			} else {
				B_alive = false;
			}
		}
	}
}

