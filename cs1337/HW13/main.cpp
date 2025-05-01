#include <string>
#include <iostream>
#include "RegularAccount.h"
#include "PremiumAccount.h"

using namespace std;

const int MAX_NUM_ACCOUNTS = 5;
// Entry point of the program
int main()
{
    Account* accountArray[MAX_NUM_ACCOUNTS] = {nullptr}; // Initialize the  address array to a null pointer
    int choice;
    
    do 
    {
        cout << "\n1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt\n";
        cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit";//
        cin >> choice;
    // Handle user's menu choice
        if (choice == 1 || choice == 2) //Create Account Type
        {
            if (Account::getNumberAccounts() >= MAX_NUM_ACCOUNTS) //Determine whether the number of accounts is overloaded
            {
                cout << "\nMax number of accounts reached, cannot add a new account\n";
                continue;
            }
        
            string name;
            string dateStr;
            double amount;
            int month, day, year, hour;
            char slash;//Skip / symbol
            
            cout << "\nEnter owner's name: ";
            cin >> name;
            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> month >> slash >> day >> slash >> year >> slash >> hour;
            cout << "Enter amount: ";
            cin >> amount;
        
            Date d;
            d.set(month, day, year, hour);//Set date information
            int index = Account::getNumberAccounts();
        // Handle user's menu choice
            if (choice == 1) 
            {
                if (amount <= 0) //Check whether the amount entered is reasonable
                {
                    cout << "Amount cannot be negative, account creation not executed\n";
                    continue;
                }
                accountArray[index] = new RegularAccount(name, amount, d);
                //Polymorphically assigning a subclass to an array of superclasses
            }
        // Handle user's menu choice
            else if (choice == 2)
            {
                if (amount <= 0) //Check whether the amount entered is reasonable
                {
                    cout << "Amount cannot be negative, account creation not executed\n";
                    continue;
                }
                else if (amount < PremiumAccount::getMinBalance()) //Check whether the amount entered is reasonable
                {
                    cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account\n";
                    continue;
                }       
                accountArray[index] = new PremiumAccount(name, amount, d);
                //Polymorphically assigning a subclass to an array of superclasses
            }
            // Confirm that the account was created successfully
            cout << "Account created: \n";
            accountArray[index]->print();
            cout << endl;
            
        }
        // Handle user's menu choice
        else if (choice == 3 || choice == 4) 
        {
            int accNo;
            cout << "\nEnter account number: ";
            cin >> accNo;

            Account* acc = nullptr;//Assign an empty address to match the account
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) 
            {
                if (accountArray[i] && accountArray[i]->getAccountNumber() == accNo) 
                //Avoid null pointer calls and check for matching account numbers
                {
                    acc = accountArray[i];
                    break;
                }
            }

            if (!acc) 
            {
                cout << "No such account\n";
                continue;
            }

            int month, day, year, hour;
            double amount;
            char slash;//Skip / symbol
            
            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> month >> slash >> day >> slash >> year >> slash >> hour;
            
            Date d;
            d.set(month, day, year, hour);//Set date information

            cout << "Enter amount: ";
            cin >> amount;

            if (amount <= 0) //Check whether the amount entered is reasonable
            {
                cout << "Amount cannot be negative, ";
                // Handle user's menu choice
                if (choice == 3)
                    cout<<"deposit";
                // Handle user's menu choice
                else if (choice == 4)
                    cout << "withdraw";
                cout <<" not executed\n";
                continue;
            }

            bool success = false;
            
            if (choice == 3)
                success = acc->deposit(amount, d);//
                
            else if (choice == 4)
                success = acc->withdraw(amount, d);//

            if (success) //Check if the operation was successful
            {
                if (choice == 3) 
                cout << "Deposit executed: \n";
                
                else if (choice == 4)
                cout << "Withdraw executed: \n";
                
                acc->print();//Display account information
                cout << endl;
            }
            else 
            {
                cout << "Insufficient balance, withdrawal not executed\n";
            }
        }
        // Handle user's menu choice
        else if (choice == 5 && Account::getNumberAccounts()==5) 
        {
            cout << "\nAccounts\n"
                 << "========\n";
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) 
            {
                if (accountArray[i]) 
                {
                    cout << endl;
                    accountArray[i]->print();
                    cout << endl;
#ifdef EXTRA_CREDIT
// Print transaction history with running balance
                    accountArray[i]->printTransactions();
#endif                    
                }
            }
            

        }
    // Handle user's menu choice
        else if (choice == 5)
            break;
        
    }while (choice != 6 );
    cout<<endl;   

    
   
    return 0;
}
   
    