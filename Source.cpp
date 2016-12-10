#include "time.h"
#include "stdio.h"
#include "iostream"
#include "math.h"

using namespace std;

// Classes

class Transaction
{
public:
	int userID;
	float amount; //float because money has cents and dollars eg. '$11.02'
	virtual void Report()
	{}
};

class Withdraw : public Transaction
{
public:
	Withdraw()
	{}
	void Report();
};

void Withdraw::Report()
{
	cout << "UserID: " << userID << "\nWithdrawn Amount: $" << amount << "\n";
}


class Deposit : public Transaction
{
public:
	Deposit()
	{}
	void Report();
};

void Deposit::Report()
{
	cout << "UserID: " << userID << "\nDeposited Amount: $" << amount << "\n";
}


class Transfer : public Transaction
{
public:
	Transfer()
	{}
	void Report();
};

void Transfer::Report()
{
	cout << "UserID: " << userID << "\nTransferred Amount: $" << amount << "\n";
}

class User
{
public:
	int id;
	int numTrans;
	Transaction* tr[100];
	void Report();
	User()
	{
		id = -1;
		numTrans = 0;
	}
};

void User::Report()
{
	cout << "Number of Transactions: " << numTrans << "\n";
}


void main()
{
	User* users[100];
	int numUsers = 0; // number of users that exist
	bool usrExist; 
	int curUser;
	bool exit = false;
	float a; // user input amount
	int t; // user input transaction choice
	int u; // user input user id


	users[numUsers] = new User();

	while (exit == false)
	{
		usrExist = false;

		cout << "Enter user id: ";
		cin >> u;

		for (int i = 0; i < numUsers; i++)
		{
			if (u == users[i]->id)
			{
				curUser = i;
				usrExist = true;
				cout << "\n*Login Successful*\n\n";
			}
		}
		if (usrExist == false)
		{
			curUser = numUsers;
			if (numUsers != 0)
				users[curUser] = new User();
			users[curUser]->id = u;
			cout << "\n*New User Created*\n\n";
			numUsers++;
		}
		if (users[curUser]->numTrans <= 100)
		{
			cout << "Enter Task From Following List: \n1) Withdraw\n2) Deposit\n3) Transfer\n4) Exit\n>";
			cin >> t;

			//create new object corresponding to action chosen
			switch (t)
			{
			case 1:
				users[curUser]->tr[users[curUser]->numTrans] = new Withdraw();
				break;
			case 2:
				users[curUser]->tr[users[curUser]->numTrans] = new Deposit();
				break;
			case 3:
				users[curUser]->tr[users[curUser]->numTrans] = new Transfer();
				break;
			case 4:
				exit = true;
				break;
			}
			if (exit == false)
			{
				cout << "Enter Amount: ";
				cin >> a;
				//set transaction amount and transaction user ID
				users[curUser]->tr[users[curUser]->numTrans]->amount = a;
				users[curUser]->tr[users[curUser]->numTrans]->userID = u;
				users[curUser]->numTrans++; // increment number of transactions done by that user
				cout << "\n";
				for (int i = 0; i < users[curUser]->numTrans; i++)
				{
					users[curUser]->tr[i]->Report();
				}

				users[curUser]->Report();
				cout << "\n";
			}
		}
		else
			break;
		
		
	}
}
