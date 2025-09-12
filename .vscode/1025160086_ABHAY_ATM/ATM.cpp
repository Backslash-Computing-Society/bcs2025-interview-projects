#include <iostream>
using namespace std;

int main() {
	string accountType;
	int choice;
	double balance = 0.0;
	double amount;
	
	//Welcome Screen
	cout<<"===================================================\n";
	cout<<"            Welcome to ABC Bank ATM\n";
	cout<<"===================================================\n";
	
	//Account Selection
	cout<<"Select Account Type: \n";
	cout<<"1. Savings Account\n";
	cout<<"2. Current Account\n";
	cout<<"Enter Choice (1 or 2): ";
	cin>> choice;
	
	if(choice == 1) {
		accountType = "Savings";
	} else if(choice == 2) {
		accountType = "Current";
	} else {
		cout<<"Invalid Choice. Exiting. \n";
		return 1;
	}
	
	cout<<"\nYou Selected: "<<accountType<<"Account\n";
	
	//Main Transaction Loop
	do{
	cout<<"\n===========================\n";
	cout<<"     Transaction Menu\n";
	cout<<"===========================\n";
	cout<<"1. Check Balance\n";
	cout<<"2. Deposit\n";
	cout<<"3. Withdraw\n";
	cout<<"4. Exit\n";
	cout<<"Enter your choice (1-4): ";
	cin>> choice;
	
	switch(choice) {
		case 1:
			cout<<"Your Current Balance is: $"<<balance<<"\n";
			break;
			
		case 2:
		    cout<<"Enter amount to deposit: $";
			cin>> amount;
			if(amount > 0) {
				balance += amount;
				cout<<"Deposited Successfully. \n";
			} else {
				cout<<"Invalid Deposit Amount. \n";
			}
			break;
			
		case 3:
		    cout<<"Enter amount to withdraw: $";
			cin>> amount;
			if(amount > 0 && amount <= balance) {
				balance -= amount;
				cout<<"Withdrawl Successful.\n";
			} else {
				cout<<"Invalid amount or insufficient balance.\n";
			}
			break;	
		
		case 4:
		    cout<<"Exiting... Thank You for using ABC Bank ATM.\n";
			cout<<"Final Balance: $"<<balance<<"\n";
			break;
			
		default:
		    cout<<"Invalid choice. Please try again.\n";			
	}
	
} while(choice != 4);

   return 0;
}
