// Muhammad Yousaf_I228797_SE-F
#include <iostream>

using namespace std;

size_t len(char *str)
{
	size_t size_str = 0;
	while (str[size_str] != '\0')
	{
		size_str++;
	}
	return size_str;
}
struct SavingAccount
{
	char *name;
	float annualInterestRate;
	double savingBalance;
	char *accountNum; /* the account numbers will be from “SA00” to “SA99”. Each
	 account must have a unique account number that has not been assigned to any
	other customer before.*/
public:
	SavingAccount()
	{
		name = nullptr;
		annualInterestRate = 0.0;
		savingBalance = 0.0;
		accountNum = new char[5];
		accountNum[0] = 'S';
		accountNum[1] = 'A';
		accountNum[2] = '0';
		accountNum[3] = '0';
		accountNum[4] = '\0';
	}
	~SavingAccount()
	{
		delete name;
		name = NULL;
		delete accountNum;
		accountNum = NULL;
	}
};
SavingAccount *savers[100]; // – an array of 100 SavingAccount pointers.
int accountsOpen = 1;		// – an integer to store the current accounts open and can also be used as an index for the customer’s array.

void OpenCustomerAccount(SavingAccount *savers[], int &accountsOpen, char *NameVal, double balance) // – a function to create a new account and assign it an account number.
{
	if (accountsOpen == 99)
	{
		cout << "maximum number of account reached" << endl;
		return;
	}
	savers[accountsOpen] = new SavingAccount();
	savers[accountsOpen]->name = new char[len(NameVal) + 1];
	if (savers[accountsOpen]->name == nullptr)
	{
		cout << "failed to allocate memory" << endl;
		return;
	}
	for (size_t i = 0; i < len(NameVal); i++)
	{
		savers[accountsOpen]->name[i] = NameVal[i];
	}
	savers[accountsOpen]->name[len(NameVal)] = '\0';

	savers[accountsOpen]->savingBalance = balance;

	savers[accountsOpen]->accountNum[2] = '0' + (accountsOpen / 10);
	savers[accountsOpen]->accountNum[3] = '0' + (accountsOpen % 10);
	// cout << savers[accountsOpen]->accountNum << endl;
	// cout << endl
	//	 << accountsOpen << endl;
	accountsOpen++;
}
float calculateMonthlyInterest(SavingAccount *savers) //- that calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12.
{
	return ((savers->annualInterestRate * savers->savingBalance) / 12.0);
}
void modifyInterestRate(SavingAccount *savers, float newValue)
{
	savers->annualInterestRate = newValue;
}
int SearchCustomer(SavingAccount *savers[], int accountsOpen, char *accountNum) // – a function that searches for an account using an account number. If the customer is found it returns the array index otherwise return -1
{
	for (size_t i = 0; i < accountsOpen; i++)
	{
		size_t j = 0;
		while (savers[i]->accountNum[j] == accountNum[j] && j < 4)
		{
			j++;
		}
		if (j == 4)
		{
			return i;
		}
	}
	return -1;
}
bool UpdateAccountBalance(SavingAccount *savers[], int accountsOpen, char *accountNumVal, double balanceVal) // – a function that updates a customer’s balance
{
	int index = SearchCustomer(savers, accountsOpen, accountNumVal);
	if (index == -1)
	{
		cout<<"customer not found"<<endl;
		return false;
	}
	savers[index]->savingBalance = balanceVal;
	return true;
}
int main()
{
}
