#include <iostream>

using namespace std;

int findId(int, int [], int);
void insertId(int, int [], int );

int main()
{
    const int MAX_SIZE = 100; 

    int sid[MAX_SIZE] = { 1, 3, 6, 8, 10}; 
    int size = 5; 
    int num, id;
    // To insert more numbers
    cout << "How many numbers do you want to insert? ";
    cin >> num;

    cout << "Enter the student ids: \n";
    for(int i = 0; i < num; i++)
    {
        cin >> id;
        int checkout = findId(id, sid, size);

        if(checkout >= 0) 
        {
            cout <<id<< " found at position " << checkout << endl;
        }
        else 
        {
            cout<<id<<" not found \n";
            cout<<id<<" inserted into the array\n";
            insertId(id, sid, size);
            size++;
        }
    }

    cout << "The array with all the elements inserted are: ";
    for(int i = 0; i < size; i++)
    {
        cout << sid[i] << " ";
    }
    cout << endl;

    return 0;
}

// should return the index of val if it is present in the array
// otherwise return -1
int findId(int val, int arrId[], int sz)
{
    for(int index = 0; index < sz; index++)
    {
        if(arrId[index] == val)
        {
            return index;
        }
    }
    return -1; 
}


void insertId(int val, int arrId[], int sz)
{
    if (sz >= 100) 
    {
        cout << "Array is full, cannot insert more elements.\n";
        return;
    }

    int i;
    for(i = sz - 1; i >= 0 && arrId[i] > val; i--) 
    {
        arrId[i + 1] = arrId[i];
    }
    arrId[i + 1] = val;
    sz++; 
}