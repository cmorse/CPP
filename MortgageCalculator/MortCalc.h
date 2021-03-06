//Joshua Morse jmorse2@cnm.edu
//MorseP6
//File: MortCalc.h

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Functions.h"
//#include "MortInfo.h"

using namespace std;

MortInfo mortData;


string MortCalc(MortInfo &mortData) {

	double interest = mortData.interest / 100;
	double monthlyPayment = (mortData.principal * interest) / (12 * (1 - (pow((1 + interest / 12), - (mortData.term * 12)))));
	double totalLoan = (monthlyPayment * 12) * mortData.term;
	double totalInterest = totalLoan - mortData.principal;

	CalcEndOfLoan(mortData);
	cout << "\n " << totalLoan << "\n " << monthlyPayment << "\n " << totalInterest;

	stringstream ss;
	ss << "\n Total Loan Amount $" << totalLoan << "\n Monthly Payment : $" << monthlyPayment
		<< "\n Total Interest $" << totalInterest
		<< "\n Start date: " << mortData.monStart << "/" << mortData.dayStart << "/" << mortData.yearStart
		<< "\n Maturaty date: " << mortData.monEnd << "/" << mortData.dayEnd << "/" << mortData.yearEnd;


	return ss.str();

}
