#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>

namespace bank_eric
{
	class BankAccount
	{
	public:
		BankAccount();
		BankAccount(std::string the_name, double the_balance);
		BankAccount(const BankAccount& copy);
		BankAccount& operator =(const BankAccount& right);
		
		void deposit(double amount);
		virtual double withdraw(double amount);
	
		std::string get_name();
		double get_balance();
		
	protected:
		std::string name;
		double balance;
	};
	
	void transfer(double amount, BankAccount& from, BankAccount& to);
	
	class MoneyMarketAccount : public BankAccount
	{
	public:
		MoneyMarketAccount();
		MoneyMarketAccount(std::string the_name, double the_balance);
		MoneyMarketAccount(const MoneyMarketAccount& copy);
		MoneyMarketAccount& operator =(const MoneyMarketAccount& right);
		
		virtual double withdraw(double amount); 
		int get_num_withdrawals();
	private:
		int num_withdrawals;
	};
	
	class CDAccount : public BankAccount
	{
	public:
		CDAccount();
		CDAccount(std::string the_name, double the_balance, double the_interest_rate);
		CDAccount(const CDAccount& copy);
		CDAccount& operator =(const CDAccount& right);
		
		virtual double withdraw(double amount);
		double get_interest_rate();
		void set_interest_rate(double new_interest_rate);
	private:
		double interest_rate;
	};
}

#endif //BANK_ACCOUNT_H
