#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Product.h"

using namespace std;
// Struct to store each transaction record
struct Transaction {
    int transactionNumber;
    string plu;
    string type; // "add" or "subtract"
    int amount;
};

int countRecords(const string&) ;// Function to count the number of product records in the file

int main() 
{
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    // Open the file for initial check
    ifstream inFile(filename);
    if (!inFile) 
    {
        cerr << "Error: Cannot open file." << endl;
        return 1;
    }

    int numRecords = countRecords(filename);
    Product* products = new Product[numRecords];

    inFile.close(); // Reopen file to read actual data
    inFile.open(filename);

    // Read product info into Product objects
    for (int i = 0; i < numRecords; i++) 
    {
        string plu;
        string name;
        int type;
        double price;
        int inv;
        
        inFile >> plu >> name >> type >> price >> inv;
        products[i].setProductAttributes(plu, name, type, price, inv);
    }

    // Display all product info after initialization
    cout << "\nContent of object array\n-----------------------" << endl;
    for (int i = 0; i < numRecords; i++) 
    {
        cout << "PLU: " << products[i].getPLU();
        cout << ", " << setw(17) << left << products[i].getName();
        cout << ", type: " << products[i].getType();
        cout << ", unit price: " << setw(5) << right << products[i].getPrice();
        cout << ", inventory: " << products[i].getInventory() << endl;
    }

    // Setup for transaction tracking
    const int MAX_TRANSACTIONS = 100;
    Transaction history[MAX_TRANSACTIONS];
    int transactionCount = 0;
    int transactionID = 1;

    // Menu loop
    int choice;
    do {
        cout << "\nMenu\n----\n";
        cout << "1->Add to inventory           , 2->Subtract from inventory\n";
        cout << "3->Print info for all products, 4->Exit\n";
        cin >> choice;

        // Fill in the switch-case logic here
        switch (choice) 
        {
            case 1:
            {   // Add to inventory
                string plu;
                int index = -1;
                cout << "Enter the PLU: ";
                cin >> plu;
                for(int i = 0; i < numRecords; i++)
                {
                    if(plu == products[i].getPLU())
                    {
                        index = i;
                        break;
                    }
                }
                if(index == -1)
                {
                    cout << "PLU not found\n";
                    break;
                }
                
                int addNum;
                int invNum;
                cout << "Enter amount to add: ";
                cin >> addNum;
                if(addNum <= 0)
                {
                    cout << "Amount must be > 0\n";
                    break;
                }
                invNum = products[index].getInventory() + addNum;
                products[index].setInventory(invNum);
                
                history[transactionCount++] = { transactionID++, plu, "Add to inventory", addNum };
                break;
            }
            case 2:
            {   // Subtract from inventory
                string plu;
                int index = -1;
                cout << "Enter the PLU: ";
                cin >> plu;
                for(int i = 0; i < numRecords; i++)
                {
                    if(plu == products[i].getPLU())
                    {
                        index = i;
                    }
                }
                if(index == -1)
                {
                    cout << "PLU not found\n";
                    break;
                }
                
                int subNum;
                int invNum;
                cout << "Enter amount to subtract: ";
                cin >> subNum;
                if(subNum <= 0)
                {
                    cout << "Amount must be > 0\n";
                    break;
                }
                int currentInv = products[index].getInventory();
                int actualSubtract = (subNum > currentInv) ? currentInv : subNum;
                invNum = currentInv - actualSubtract;
                products[index].setInventory(invNum);
                
                history[transactionCount++] = { transactionID++, plu, "Subtract from inventory", actualSubtract };
                break;
            }
            case 3:
            {
                // Print product info
                cout << "Current inventory\n";
                cout << "-----------------\n";
                for (int i = 0; i < numRecords; ++i) 
                {
                    cout << "PLU: " << products[i].getPLU()
                         << ", " << setw(17) << left << products[i].getName()
                         << ", type: " << products[i].getType()
                         << ", unit price: " << setw(5) << right << products[i].getPrice()
                         << ", inventory: " << products[i].getInventory() << endl;
                }
                break;
            }
            case 4:
            {   // Exit and print recent history
                cout << "\nHistory of transactions\n";
                cout << "-----------------------" << endl;
                int times = (transactionCount > 5) ? 5 : transactionCount;
                for (int i = 0; i < times; i++)
                {
                    cout << "Transaction #: " << history[transactionCount-1-i].transactionNumber;
                    cout << ", PLU: " << history[transactionCount-1-i].plu;
                    cout << ", type: " << history[transactionCount-1-i].type;
                    cout << ", amount: " << history[transactionCount-1-i].amount << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    // Clean up memory
    delete[] products;
    return 0;
}

// Helper function to count how many product lines are in the file
int countRecords(const string& filename) 
{
    ifstream file(filename);
    string line;
    int count = 0;
    while (getline(file, line)) 
    {
        count++;
    }
    cout << "There are "<< count<<" records in the file\n";
    return count;
}