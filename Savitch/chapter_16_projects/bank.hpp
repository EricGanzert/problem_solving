#ifndef BANK_H
#define BANK_H

namespace bank_eric
{
	class InvalidDeposit {};
	class InsufficientFunds {};
	
	class Account
	{
	private:
		double balance;
	public:
		Account();
		Account(double initial_deposit);
		double getBalance();
		double deposit(double amount) throw(InvalidDeposit);
		//returns new balance
		double withdraw(double amount) throw(InsufficientFunds);
		//returns new balance
	};
}

#endif //BANK_H
