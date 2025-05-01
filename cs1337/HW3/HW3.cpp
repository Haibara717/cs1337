#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


bool readInventory(string fname, int numRecords, string * pluPtr, double * pricePtr,string * namePtr, int * typePtr, int * inventoryPtr);

int determineNumRecords(string fname);

double checkout(int numRecords, string * pluPtr, double * pricePtr,int * inventoryPtr);

int getUserChoice();

int searchProduct(string plu, string *pluPtr, int numRecords);

int main()
{
    string filename;
    cout<<"Enter the file name: ";
    cin>>filename;
    
    int numRecords = determineNumRecords(filename);
    cout<<"There are "<<numRecords<<" records in the file\n";
    cout<<endl;
    
    string* pluPtr = new string[numRecords];      
    double* pricePtr = new double[numRecords];    
    string* namePtr = new string[numRecords];     
    int* typePtr = new int[numRecords];           
    int* inventoryPtr = new int[numRecords];  
    
    bool isopen=readInventory(filename,numRecords,pluPtr,pricePtr,namePtr,typePtr,inventoryPtr);
    if(!isopen)
    {
        cout<<"inputfile failed !\n";
    }
    
    
    cout<<"Inventory read from file\n";
    cout<<"------------------------\n";
    for(int i = 0 ; i < numRecords;i++)
    {
        cout<<"PLU: "<<pluPtr[i]<<", "<<setw(17)<<left<<namePtr[i]<<", type: "<<typePtr[i]<<", unit price:"<<setw(6)<<right<<pricePtr[i]<<", inventory: "<<inventoryPtr[i]<<endl;
    }
    
    
    int choice = 0;
    while(choice != 3)
    {
        choice = getUserChoice();
        
        if(choice == 1)
        {
            double total = checkout(numRecords, pluPtr, pricePtr,inventoryPtr);
            cout<<"Total is: $"<<total<<endl;
        }
        
        if(choice == 2)
        {
            cout<<"Current inventory\n";
            cout<<"-----------------\n";
            for(int i = 0 ; i < numRecords;i++)
            {
                cout<<"PLU: "<<pluPtr[i]<<", "<<setw(17)<<left<<namePtr[i]<<", type: "<<typePtr[i]<<", unit price:"<<setw(6)<<right<<pricePtr[i]<<", inventory: "<<inventoryPtr[i]<<endl;
            } 
        }
        
        if(choice == 3)
        {
            
            cout<<"Updated inventory\n";
            cout<<"-----------------\n";
            for(int i = 0 ; i < numRecords;i++)
            {
                cout<<"PLU: "<<pluPtr[i]<<", "<<setw(17)<<left<<namePtr[i]<<", type: "<<typePtr[i]<<", unit price:"<<setw(6)<<right<<pricePtr[i]<<", inventory: "<<inventoryPtr[i]<<endl;
            } 
            
            cout<<"Exiting\n";
            
            
            delete[] pluPtr;
            delete[] pricePtr;
            delete[] namePtr;
            delete[] typePtr;
            delete[] inventoryPtr;
            
            return 0;
            
        }
    }
}

int determineNumRecords(string fname)
{
    ifstream inputfile(fname);
    if (!inputfile)
    {
        cout << "Error: Cannot open file " << fname << endl;
        return 0;
    }

    int count = 0;
    string line;
    
    while (getline(inputfile, line))
    {
        if (!line.empty())
        {
            count++;
        }
    }
    
    inputfile.close();
    return count;
}
bool readInventory(string fname, int numRecords, string * pluPtr, double * pricePtr,string * namePtr, int * typePtr, int * inventoryPtr)
{
    ifstream inputfile;
    inputfile.open(fname);
    if(!inputfile)
    {
        return 0;
    }
    
    int count = 0;
    while(count < numRecords)
    {
        inputfile>>pluPtr[count];
        inputfile>>namePtr[count];
        inputfile >> typePtr[count] >> pricePtr[count] >> inventoryPtr[count];
        
        count++;
    }
    
    inputfile.close();
    return 1;
}
int getUserChoice()
{
    int choice;
    
    cout<<"1 - Checkout\n";
    cout<<"2 - Print current inventory\n";
    cout<<"3 - Quit\n";
    
    do
    {
        cin>>choice;
        if(choice < 1 || choice > 3)
        {
            cout<<"Invalid choice, reenter: \n";
            
        }
    }while (choice < 1 || choice > 3);
    
    return choice;
}
double checkout(int numRecords, string * pluPtr, double * pricePtr,int * inventoryPtr)
{
    string plu = "plu";
    int qua;
    double total = 0;
    
    while(plu != "0")
    {
        cout<<"Enter PLU, 0 if done: ";
        cin>>plu;
        if(plu == "0")
        {
            return total;
        }
        
        cout<<"Enter quantity: ";
        cin>>qua;
        while(qua<1)
        {
            cout<<"Quantity must be positive, reenter: ";
            cin>>qua;
        }
        
        int index =searchProduct(plu,pluPtr,numRecords);
        if(index == -1)
        {
            cout<<"PLU not found\n";
            cout<<endl;
            continue;
        }
        else
        {
            
            int numSold = (qua < inventoryPtr[index]) ? qua : inventoryPtr[index];
            total += numSold*pricePtr[index];
            inventoryPtr[index] -= numSold;
        }
        
    }
    return total;
}
int searchProduct(string plu, string *pluPtr, int numRecords)
{
    for(int i = 0; i < numRecords; i++)
    {
        if(pluPtr[i] == plu)
        {
            return i;
        }
    }
    return -1;
}