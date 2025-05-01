#include "PremiumAccount.h"

#include <iostream>
#include <string>

using namespace std;

const double PremiumAccount::MIN_BALANCE = 1000.0;

PremiumAccount::PremiumAccount(string nam, double amt, Date d):Account(nam,amt,d)
{
    
}
// Attempt to withdraw money if balance is sufficient
bool PremiumAccount::withdraw(double amnt,Date d)
{
    if ((balance - amnt) > MIN_BALANCE)
    {
        balance -= amnt;
        
        Transaction t;
        t.date = d;
        t.transactionType = 2; // 2 = withdrawal
        t.amount = amnt;
        // Append a transaction to the dynamic transaction history array
        recordTransaction(t);
        
        return true;
    }
    return false;
}
double PremiumAccount::getMinBalance() 
{
    return MIN_BALANCE;
}
void PremiumAccount::print() const
{
    cout << "Premium account, ";
    this->Account::print();
}


