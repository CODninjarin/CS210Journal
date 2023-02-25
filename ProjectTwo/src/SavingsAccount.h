#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

using namespace std;

class SavingsAccount{
   public:
	SavingsAccount();
	SavingsAccount(double t_Value, double t_MonthlyIncrease, double t_InterestRate, int t_NumYears);
	void setValue(double t_Value);
	double getValue();
	void setMonthlyIncrease(double t_MonthlyIncrease);
	double getMonthlyIncrease();
	void setInterestRate(double t_InterestRate);
	double getInterestRate();
	void setNumYears(int t_NumYears);
	int getNumYears();
	void drawInputMenu();
	void drawOutputTables();
	double getMonthlyInterest(double t_Value);
	double getMonthlyInterest(double t_Value, double t_MonthlyIncrease);
	double getAnnualBalance(double t_Value);
	double getAnnualBalance(double t_Value, double t_MonthlyIncrease);
   private:
	double m_Value, m_MonthlyIncrease, m_InterestRate;
	int m_NumYears;
};

#endif