
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void dollarFormat(string &);
int main() {
 
string dollar;
 
cout << "Enter the dollar amount: ";
 
cin >> dollar;
 
 
dollarFormat(dollar);
 
 
cout << "New amount: " << dollar << endl;
 
return 0;
}
void dollarFormat(string &str) {
 
 
double num = stod(str);
 
 
 
str = to_string(num);
 
size_t dotPos = str.find('.');
 
if (dotPos == -1)
 
{
 
str += ".00";
 
 
} else 
 
{
 
str = str.substr(0, dotPos + 3);
 
 
}
 
 
dotPos = str.find('.');
 
string intPart = str.substr(0, dotPos);
 
string decimalPart = str.substr(dotPos); 
 
 
int count = 0;
 
for (int i = intPart.size() - 1; i > 0; --i) {
 
count++;
 
if (count % 3 == 0) {
 
intPart.insert(i, ",");
 
}
 
}
 
 
str = "$" + intPart + decimalPart;
}