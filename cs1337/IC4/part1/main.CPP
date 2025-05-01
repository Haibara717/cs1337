#include <iostream>
using namespace std;
#define SIZE 10

void SelectionSort(int [], int size );
void swap(int & , int &);
int main()
{
   // Declare all the variables and arrays
   int array[SIZE];
   int elementNum;
   // input validation
   cout<<"How many elements?\n";
   cin>>elementNum;
   while(elementNum <=0 || elementNum >10)
   {
    cout<<"The number of elements should be less than 11 and greater than 0\n";
    cin>>elementNum;
   }
   // Read data from  keyboard and populate arrays
   cout<<"Enter the elements:\n";
   for(int i = 0; i <elementNum;i++)
   {
       
       cin>>array[i];
   }
   // call the selection sort function
   SelectionSort(array,elementNum);
   // SelectionSort(numberList, numberRec);
    
    // Display the sorted array
    cout<<"The sorted array is :";
    for(int i = 0; i<elementNum; i++)
    {
        cout<<" "<<array[i];
    }
    
    return 0;
}

void SelectionSort(int numbers[], int size)
{
   // body of the function
   for(int times = size-1; times>0; times--)
   {
       for(int i = 0;i<times;i++)
       {
           if(numbers[i]>numbers[i+1])
           {
               swap(numbers[i],numbers[i+1]);
           }
       }
   }
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
