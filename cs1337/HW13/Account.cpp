#include "Account.h"
#include "Common.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int Account::numberAccounts = 0;

#ifdef EXTRA_CREDIT
// Append a transaction to the dynamic transaction history array
void Account::recordTransaction(Transaction t)
{
    Transaction* newHistory = new Transaction[numberTransactions + 1];
    if (transactionHistory != nullptr) 
    {
        for (int i = 0; i < numberTransactions; i++)
        {
            newHistory[i] = transactionHistory[i];
        }
        delete[] transactionHistory;
    }
    
    transactionHistory = newHistory;
    newHistory[numberTransactions] = t;
    numberTransactions++;
}
#endif
// Constructor for Account class
Account::Account(string nam, double bal, Date d)
{
    ownerName = nam;
    balance = bal;
    
    accountNumber = numberAccounts + 1000;
    numberAccounts++;
#ifdef EXTRA_CREDIT     
    transactionHistory = nullptr;
    numberTransactions = 0;
#endif  

#ifdef EXTRA_CREDIT    
    Transaction t;
    t.date = d;
    t.transactionType = 0; // 0 = account creation
    t.amount = bal;
// Append a transaction to the dynamic transaction history array
    recordTransaction(t);
#endif    
}
// Attempt to withdraw money if balance is sufficient
bool Account::withdraw(double amount, Date d)
{
    if (balance >= amount)
    {
        balance -= amount;
#ifdef EXTRA_CREDIT        
        Transaction t;
        t.date = d;
        t.transactionType = 2; // 2 = withdrawal
        t.amount = amount;
// Append a transaction to the dynamic transaction history array
        recordTransaction(t);
#endif        
        return true;
    }
    return false;
}
// Attempt to deposit money if amount is positive
bool Account::deposit(double amount, Date d)
{
    if (amount > 0)
    {
        balance += amount;
#ifdef EXTRA_CREDIT        
        Transaction t;
        t.date = d;
        t.transactionType = 1; // 1 = deposit
        t.amount = amount;
    // Append a transaction to the dynamic transaction history array
        recordTransaction(t);
#endif        
        return true;
    }
    return false;
}
int Account::getAccountNumber() const
{
    return accountNumber;
}
double Account::getBalance() const
{
    return balance;
}
int Account::getNumberAccounts() 
{
    return numberAccounts;
}
#ifdef EXTRA_CREDIT
// Print transaction history with running balance
void Account::printTransactions() const
{
    double simulatedBalance = 0.0;
    
    
    
    cout << "Transaction history:\n"
         << "-------------------\n";
         
    for (int i = 0; i < numberTransactions; i++)
    {
        cout << "Date: ";
        transactionHistory[i].date.print(); 
        
        cout << ", Amount: " << fixed << setprecision(2) << transactionHistory[i].amount;

        switch(transactionHistory[i].transactionType)
        {
            case 0: 
                cout << ", type: Creation";
                simulatedBalance = transactionHistory[i].amount; // 
                break;
            case 1: 
                cout << ", type: Deposit";
                simulatedBalance += transactionHistory[i].amount;
                break;
            case 2: 
                cout << ", type: Withdrawal";
                simulatedBalance -= transactionHistory[i].amount;
                break;
        }
        cout << ", New balance: " << fixed << setprecision(2) << simulatedBalance << endl;
    }
}
#endif
void Account::print() const
{
    cout << "#: " << accountNumber 
         << ", Name: " << ownerName 
         
         << ", Balance: " << fixed << setprecision(2)<< balance 
         <<" Galactic units";
}