#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXPRODUCTS = 100;
string names[MAXPRODUCTS];
double prices[MAXPRODUCTS];
string codes[MAXPRODUCTS];
int numProducts = 0;

int findItem(string inputCode);
void readConfiguration();
void display();
void process();

int main() 
{
   readConfiguration();
   display();
   process();
   return 0;
}

void readConfiguration() 
{
    ifstream inputfile;
    inputfile.open("menu.txt");
    if(!inputfile)
    {
        cout<<"Could not open file"<<endl;
    }
    
    while(numProducts<MAXPRODUCTS&&inputfile>>codes[numProducts]>>names[numProducts]>>prices[numProducts])
    {
        numProducts++;
    }
    
   // Code here to Read the values into arrays
    cout << numProducts << " items loaded.\n";
}

void display()
{
    cout << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(8)   <<  "Codes"
                            << setw(25) << "Item Name"
                             << setw(4)  <<  "Prices" << endl;
    cout << "--------------------------------------------------------------------------"  << endl;
    //code here
    //Print the values from their respective arrays
    for(int i = 0; i < numProducts; i ++)
    {
        cout << left << setw(8)   <<codes[i]<<setw(25) <<names[i]<< setw(4)  <<prices[i]<<endl;
    }
}
//return valid index if the item is found, return -1 otherwise.
int findItem(string inputCode) 
{
    //code here!
    
    for(int i = 0; i < numProducts; i++)
    {
        if(codes[i] == inputCode)
        {
            return i ;
        }
    }
    

    return -1;
}

// read order string like "A1 A2 E1 E2 S1" and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() 
{
    double total = 0;
    //code here
    string code;
    cout<<"Enter your order string:";
    getline(cin,code);
    int sz = code.length();
    int x = 0;
    while (x < sz)
    {
        while (x < sz && code[x] == ' ') 
        {
            x++;
        }
        if (x + 1 < sz) 
        {
            string input = code.substr(x, 2);
            int result = findItem(input);
            if (result == -1)
            {
                cout << input << " is invalid. Skipping it.\n";
            }
            else
            {
                cout << fixed << setprecision(2);
                cout << names[result] << ": $" << prices[result] << endl;
                total += prices[result];
            }
            x += 2;
        }
        
        
    }
    cout << "Total: $" << total << endl;
}

