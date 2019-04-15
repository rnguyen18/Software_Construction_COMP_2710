//Ryan Nguyen
//rmn0010
//hw1_rmn0010.cpp
//The program calculates the fatal amount of diet coke.
//I didn't get any extra help.

#include<iostream>
using namespace std;

int main()
{
	double mouseWeight = 0;
	double fatalSweetenerAmount = 0;
	double weightOfFriend = 0;
	double sweetenerFraction = 0.001;

	cout << "Please input the weight of the mouse in kg" << endl;
	cin >> mouseWeight;

	cout << "Please input the fatal amount of sweetener for mouse in kg"<< endl;
	cin >> fatalSweetenerAmount;

	cout << "Please input the weight of your dear friend in kg" << endl;
	cin >> weightOfFriend;

	double fatalCoke = (fatalSweetenerAmount * weightOfFriend) / (mouseWeight * sweetenerFraction);

	cout << "The fatal amount of Coke for your friend is: " << fatalCoke << " kg" << endl;

}
