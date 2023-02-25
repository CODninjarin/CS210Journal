#include <iostream>
#include <iomanip>
using namespace std;

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(){ // default constructor, initializes all variables to 0
	m_Value = 0;
	m_MonthlyIncrease = 0;
	m_InterestRate = 0;
	m_NumYears = 0;
}
SavingsAccount::SavingsAccount(double t_Value, double t_MonthlyIncrease, double t_InterestRate, int t_NumYears){  // constructor using user provided variables
	m_Value = t_Value;
	m_MonthlyIncrease = t_MonthlyIncrease;
	m_InterestRate = t_InterestRate;
	m_NumYears = t_NumYears;
}

//Setters and Getters for private class variables
void SavingsAccount::setValue(double t_Value){m_Value = t_Value;}
double SavingsAccount::getValue() {return m_Value;}
void SavingsAccount::setMonthlyIncrease(double t_MonthlyIncrease){m_MonthlyIncrease = t_MonthlyIncrease;}
double SavingsAccount::getMonthlyIncrease(){return m_MonthlyIncrease;}
void SavingsAccount::setInterestRate(double t_InterestRate){m_InterestRate = t_InterestRate;}
double SavingsAccount::getInterestRate(){return m_InterestRate;}
void SavingsAccount::setNumYears(int t_NumYears){m_NumYears = t_NumYears;}
int SavingsAccount::getNumYears(){return m_NumYears;}

// function to draw account menu 
void SavingsAccount::drawInputMenu(){
	cout << "******************************" << endl;
	cout << "* Initial Value:  $" << m_Value << endl;
	cout << "* Monthly Input:  $" << m_MonthlyIncrease << endl;
	cout << "* Annual Interest Rate:  %" << m_InterestRate << endl;
	cout << "* Years to Simulate:  " << m_NumYears << endl;
	cout << "* Press E to change values" << endl;
	cout << "* Press C to continue" << endl; 
	cout << "* Press Q to exit" << endl;
	cout << "******************************" << endl;
}

// function to draw output tables
void SavingsAccount::drawOutputTables(){
	cout << "******************************************************************************************" << endl;
	cout << "*                       Yearly Balances without monthly increase                         *" << endl;
	cout << "*----------------------------------------------------------------------------------------*" << endl;
	cout << "*  Year  |           |              EOY Balance               EOY Interest Accrued       *" << endl;
	cout << "*----------------------------------------------------------------------------------------*" << endl;
	double CurrValue = m_Value;
	double CurrInterest = 0.0;
	for (int i = 0; i < m_NumYears; i++) {
		cout << fixed << setprecision(2) << "    " << i+1 << "                                  " << getAnnualBalance(CurrValue, 0.0) << "                            " << (12.0 * getMonthlyInterest(CurrValue, 0.0)) << endl;
		CurrValue = getAnnualBalance(CurrValue, 0.0);
		CurrInterest = (12.0 * getMonthlyInterest(CurrValue, 0.0));
	}
	cout << "******************************************************************************************" << endl;
	cout << "*                         Yearly Balances with monthly increase                          *" << endl;
	cout << "*----------------------------------------------------------------------------------------*" << endl;
	cout << "*  Year  |           |              EOY Balance               EOY Interest Accrued       *" << endl;
	cout << "*----------------------------------------------------------------------------------------*" << endl;
	CurrValue = m_Value;
	CurrInterest = 0.0;
	for (int i = 0; i < m_NumYears; i++) {
		
		cout << fixed << setprecision(2) << "    " << i + 1 << "                                  " << getAnnualBalance(CurrValue) << "                            " << (12.0 * getMonthlyInterest(CurrValue)) << endl;
		CurrValue = getAnnualBalance(CurrValue);
		CurrInterest = (12.0 * getMonthlyInterest(CurrValue));
	}
	cout << "******************************************************************************************" << endl;
}

// functions for monthly interest accrual
double SavingsAccount::getMonthlyInterest(double t_Value){  // uses default monthly increase
	return ((t_Value + m_MonthlyIncrease) * ((m_InterestRate / 100.0)/12));
}
double SavingsAccount::getMonthlyInterest(double t_Value, double t_MonthlyIncrease) { // uses user provided monthly increase
	return ((t_Value + t_MonthlyIncrease) * ((m_InterestRate / 100.0)/12));
}

// functions used to return annual balance
double SavingsAccount::getAnnualBalance(double t_Value){ // uses default monthly increase
	for (int i = 0; i < 12; i++) {
		t_Value += m_MonthlyIncrease + getMonthlyInterest(t_Value);
	}
	return t_Value;
}
double SavingsAccount::getAnnualBalance(double t_Value, double t_MonthlyIncrease){ // uses user provided monthly increase
	for (int i = 0; i < 12; i++) {
		t_Value += t_MonthlyIncrease + getMonthlyInterest(t_Value,t_MonthlyIncrease);
	}
	return t_Value;
}

