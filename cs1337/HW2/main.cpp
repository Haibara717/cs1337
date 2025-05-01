#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <fstream>

using namespace std;

void modifiedSortGPA(double array1[], int array2[], string array3[], int numElems);
void modifiedSortID(int array2[], double array1[], string array3[], int numElems);
void swap(int & , int &);
//double randGPA();
int getUserChoice();
int linearSearchID(int arr[], int numElems, int ID, int &nIter);
int binarySearchID(int arr[], int numElems, int ID, int &nIter);

int main()
{
    /********************************************
    Start of code that Students should copy and paste
    *******************************************/
    const int NUM_ELMTS = 18;
    ifstream inputfile;
    string filename;
    
    cout<<"Enter file name: ";
    cin>>filename;
    
// netID and GPA are parallel arrays
    int netID[NUM_ELMTS]; // Original netID array
    double GPA[NUM_ELMTS]; // Original GPA array
    string major[NUM_ELMTS]; // Original major array
    
    inputfile.open(filename);
    if(!inputfile)
    {
        cout<<"Could not open file"<<endl;
        cout<<"Exiting\n";
        return 0;
    }
    int i = 0;
    while(i<NUM_ELMTS&&inputfile>>netID[i]>>major[i]>>GPA[i])
    {
        i++;
    }
    int numElems=i;
    
    
    

// sortedNetIDbyGPA and sortedGPAbyGPA are parallel arrays
    int sortedNetIDbyGPA[NUM_ELMTS]; // netID array,sorted by GPA
    double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
    string sortedMajorbyGPA[NUM_ELMTS]; // Major array, sorted by GPA
    for(int i = 0; i < numElems; i++)
    {
        sortedNetIDbyGPA[i] = netID[i];
        sortedGPAbyGPA[i] = GPA[i];
        sortedMajorbyGPA[i] = major[i];
        
    }
    modifiedSortGPA(sortedGPAbyGPA,sortedNetIDbyGPA,sortedMajorbyGPA,numElems);
   
// sortedNetIDbyID and sortedGPAbyID are parallel arrays
    int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
    double sortedGPAbyID[NUM_ELMTS]; // GPA array, sorted by netID
    string sortedMajorbyID[NUM_ELMTS]; // Major array, sorted by netID
    for(int i = 0; i < numElems; i++)
    {
        sortedNetIDbyID[i] = netID[i];
        sortedGPAbyID[i] = GPA[i];
        sortedMajorbyID[i] = major[i];
    }
    modifiedSortID(sortedNetIDbyID,sortedGPAbyID,sortedMajorbyID,numElems);
    
    
    
    
    cout<<"Original arrays:\n";
    cout<<"----------------\n";
    cout<<"index  netID  major   GPA   index  netID  major   GPA\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < numElems; i += 2)
    {
        cout<<setw(5)<<i<<setw(7)<<netID[i]<<setw(7)<<major[i]<<setw(6)<<GPA[i]<<"   ";
        if(i+1 < numElems)
        {
            cout<<setw(5)<<i+1<<setw(7)<<netID[i+1]<<setw(7)<<major[i+1]<<setw(6)<<GPA[i+1];
        }
        cout<<endl;
    }
    
    cout<<"Arrays sorted by GPA:\n";
    cout<<"---------------------\n";
    cout<<"index  netID  major   GPA   index  netID  major   GPA\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < numElems; i += 2)
    {
        int idx1 = i;
        int idx2 = i + 1;

        cout << setw(5) << i << setw(7) << sortedNetIDbyGPA[idx1] << setw(7) << sortedMajorbyGPA[idx1] << setw(6) << sortedGPAbyGPA[idx1] << "   ";
        if (idx2 < numElems)
            {
                cout << setw(5) << i + 1 << setw(7) << sortedNetIDbyGPA[idx2] << setw(7) << sortedMajorbyGPA[idx2] << setw(6) << sortedGPAbyGPA[idx2];
            }
        cout << endl;
}
    
    cout<<"Arrays sorted by netID:\n";
    cout<<"-----------------------\n";
    cout<<"index  netID  major   GPA   index  netID  major   GPA\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < numElems; i += 2)
    {
        cout<<setw(5)<<i<<setw(7)<<sortedNetIDbyID[i]<<setw(7)<<sortedMajorbyID[i]<<setw(6)<<sortedGPAbyID[i]<<"   ";
        if(i+1 < numElems)
        {
            cout<<setw(5)<<i+1<<setw(7)<<sortedNetIDbyID[i+1]<<setw(7)<<sortedMajorbyID[i+1]<<setw(6)<<sortedGPAbyID[i+1];
        }
        cout<<endl;
    }
    
    /********************************************
    End of code that Students should copy and paste
    *******************************************/
    int choice = 0;
    int n,Netid;
    int iterLI = 0,iterBI = 0;
    while(choice != 3)
    {
        choice = getUserChoice();
        switch(choice)
        {
            case 1 :
            {
                
                cout<<"Enter n: \n";
                cin>>n;
                if(n>numElems)
                {
                    n=numElems;
                }
                cout<<"Top "<<n<<" students are:"<<endl;
                    cout<<endl;
                for(int i = numElems-1 ; i >= numElems-n; i--)
                {

                    cout<<"netID: "<<sortedNetIDbyGPA[i]<<", major: "<<sortedMajorbyGPA[i]<<", GPA: "<< fixed << setprecision(2)<<sortedGPAbyGPA[i]<<endl;
                }
                break;
            }
            case 2 :
            {
                cout<<"Enter netID:\n";
                cin>>Netid;
                
                int indexL = linearSearchID(netID, numElems, Netid, iterLI);
                if(indexL<0)
                {
                    cout<<"Result of linear search:"<<endl;
                    cout<<"------------------------\n";
                    cout<<"Student not found\n";
                    cout<<"It took "<<iterLI<<" iterations\n";
                }
                else
                {
                    cout<<"Result of linear search:"<<endl;
                    cout<<"------------------------\n";
                    cout<<"Student found at index "<<indexL<<", GPA is "<<GPA[indexL]<<endl;
                    cout<<"It took "<<iterLI<<" iterations\n";
                }
                
                int indexB = binarySearchID(sortedNetIDbyID, numElems, Netid, iterBI);
                if(indexB<0)
                {
                    cout<<"Result of binary search:"<<endl;
                    cout<<"------------------------\n";
                    cout<<"Student not found\n";
                    cout<<"It took "<<iterBI<<" iterations\n";
                }
                else
                {
                    cout<<"Result of binary search:"<<endl;
                    cout<<"------------------------\n";
                    cout<<"Student found at index "<<indexB<<", GPA is "<<sortedGPAbyID[indexB]<<endl;
                    cout<<"It took "<<iterBI<<" iterations\n";
                }
                break;
            }
            case 3 :
            {
                cout<<"Exiting\n";
                break;
            }
        }
        
    }
    return 0;
}

int getUserChoice()
{
    int choice;
    cout<<"***************\n";
    cout<<"Menu of choices\n";
    cout<<"***************\n";
    cout<<"1 - List top n students\n";
    cout<<"2 - Search on a netID\n";
    cout<<"3 - Quit\n";
    cin>>choice;
    return choice;
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void modifiedSortGPA(double array1[], int array2[], string array3[], int numElems)
{
    for(int i = 0; i < numElems-1;i++)
    {
        for(int j = 0;j < numElems-1-i;j++)
       {
           if(array1[j] > array1[j+1])
           {
               swap(array1[j],array1[j+1]);
               swap(array2[j],array2[j+1]);
               swap(array3[j],array3[j+1]);
           }
       }
    }
    
}
void modifiedSortID(int array2[], double array1[], string array3[], int numElems)
{
    int minIndex;
    for(int i = 0; i < numElems-1;i++)
    {
        
        minIndex=i;
        for(int j = i+1; j < numElems;j++)
        {
            if(array2[j] < array2[minIndex])
            {
                
                minIndex = j;
            }
        }
        swap(array1[minIndex],array1[i]);
        swap(array2[minIndex],array2[i]);
        swap(array3[minIndex],array3[i]);
    }
}
int linearSearchID(int arr[], int numElems, int ID, int &nIter)
{
    nIter = 0;
    for(int i = 0; i< numElems; i++)
    {
        nIter++;
        if(arr[i] == ID)
        {
            return i;
        }
    }
    return -1;
}
int binarySearchID(int arr[], int numElems, int ID, int &nIter)
{
    
    nIter = 0;
    int low = 0, high = numElems-1;
    while(low <= high)
    {
        nIter++;
        int middle = low +(high - low)/2;
        if(arr[middle] == ID)
        {
            return middle;
        }
        else if(arr[middle]<ID)
        {
            low=middle+1;
        }
        else if(arr[middle]>ID)
        {
            high=middle-1;
        }
    }
    
    return -1;
    
}