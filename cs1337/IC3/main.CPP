#include <iostream>

using namespace std;

//prototype
int binarySearch(int list[], int key, int low, int high);

// function main begins program execution
int main()
{
    int list[] = { 2, 4, 7, 10, 11, 28, 34, 45, 50, 59, 60, 66, 69, 70, 75, 89, 95 };

    int key, first = 0, last = 16;
    cout <<"Enter the element to search: ";
    cin >> key;
    
    int index = binarySearch(list,key,first,last);
    if(index >=0)
    cout<<key<<" is at index "<<index;
    else;
    
    return 0;



}

   // function definition
  // Write your  Function header
int binarySearch(int list[], int key, int low, int high)
{
    int count = 0;
    
    int middle=0;
    while(low<=high)
    {
        count++;
        middle = (high+low)/2;
        if(list[middle]==key)
        {
            cout << "It takes "<< count << " iterations to find the key " << key  << endl;
            
            return middle;
        }
        else if(list[middle]<key)
        {
            low=middle+1;
        }
        else if(list[middle]>key)
        {
            high=middle-1;
        }
        
    }
  // Write your code here and the two cout statements be inserted into your code wherever necessary
    cout << "After  "<< count << " iterations "<< key << " is not found!" << endl;
    return -1;
}
