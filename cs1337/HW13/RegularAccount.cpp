#include "RegularAccount.h"

#include <iostream>
#include <string>

using namespace std;



RegularAccount::RegularAccount(string nam, double amt, Date d):Account(nam,amt,d)
{
   //
}


void RegularAccount::print() const
{
    cout << "Regular account, ";
    this->Account::print();
}


