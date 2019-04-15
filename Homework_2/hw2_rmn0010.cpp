//Ryan Nguyen
//rmn0010
//hw2_rmn0010.cpp
//The program calculates a table that determines the amount of months taken to pay off a loan as well as printing out other attributes of the loan such as loan amount, loan payment, rate interest, and principal.
//I didn't get any extra help.

#include<iostream>
#include<iomanip>
using namespace std;

void PrintAsterisk() {
	for (int i = 0; i < 54; i++) {
		cout << "*";
	}
	cout << endl;
}

void PrintMoney(double dolla) {
	cout << "$" << dolla << "\t";
}

int main()
{
	cout << fixed << showpoint << setprecision(2);	
	double loanAmount = 0.0;
	double interestRatePerYear = 0.0;
	double monthlyPayments = 0.0;
	double monthlyRate = 0.0;

	cout << "Loan Amount: "; 
	cin >> loanAmount;

	cout << "Interest Rate (\% per year): ";
	cin >> interestRatePerYear;

	cout << "Monthly Payments: ";
	cin >> monthlyPayments;
	cout << endl;	
	
	monthlyRate = interestRatePerYear/1200;

	if (monthlyPayments > loanAmount*monthlyRate) {	
		PrintAsterisk();
		cout << "\tAmortization Table" << endl;
		PrintAsterisk();
		cout << "Month\t" << "Balance\t" << "Payment\t" << "Rate\t" << "Interest\t" << "Principal" << endl;
		cout << "0\t$" << loanAmount << "\tN/A" << "\tN/A" << "\tN/A" << "\tN/A" << endl;	
		int month = 1;
		double payment = 0;
		double rate = interestRatePerYear/12;
		double interest = loanAmount*monthlyRate;
		double totalInterest = 0;
		while ((monthlyPayments - interest) < loanAmount) {
			loanAmount -= (monthlyPayments - interest);
			totalInterest += interest;
			cout << month++ << "\t";
			//cout << "$" << loanAmount << "\t";
			PrintMoney(loanAmount);
			//cout << "$" << monthlyPayments << "\t";
			PrintMoney(monthlyPayments);
			cout << rate << "\t";
			//cout << "$" << interest << "\t";
			PrintMoney(interest);
			//cout << "$" << monthlyPayments - interest << "\t";
			PrintMoney(monthlyPayments - interest);
			cout << endl;
			interest = loanAmount*monthlyRate;
		}
	
		totalInterest += interest;
		cout << month << "\t";
		PrintMoney(0);
		PrintMoney(loanAmount);
		cout << rate << "\t";
		PrintMoney(interest);
		PrintMoney(interest + loanAmount);
		cout << endl;
		PrintAsterisk();
		cout << endl << "It takes " << month << " months to pay off the loan.";
		cout << endl << "Total interest paid is: ";
		PrintMoney(totalInterest);
		cout << endl;
	} else {
	
		cout << "Payments are not larger than monthly interest.\nUnable to calculate the table!" << endl;

	}
}

