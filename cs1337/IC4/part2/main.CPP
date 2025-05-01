#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 100

void SelectionSort(int [], int size );
void swap(int & , int &);
//void SelectionSort(int numbers[], int numbersSize);
int main()
{
    int numberList[SIZE];
    int numberRec;

    cout << "How many elements? " ;
    cin >> numberRec;

    // input validation
    while( numberRec <=0 || numberRec>SIZE)
    {
        cout << "The number of elements should be less than " << SIZE+1 << " or greater than 0" << endl;
        cin >> numberRec;

    }
    int seed;
    cout << "Enter a seed value: ";
    cin >> seed;
    srand(seed);
    cout << "The array after populating value is: " << endl;
    
// Read data from  keyboard and populate arrays

    for(int i = 0; i<numberRec; i++)
    {
        numberList[i] = (rand()%50);
         cout << setw(3) <<  numberList[i];
        
    }
         
    
    cout << endl;
    // call the selection sort function
    SelectionSort(numberList, numberRec);

    // Display the sorted array
    cout << "The sorted array is : " << endl;
    for(int i = 0; i<numberRec; i++)
    {
        cout << setw(3) <<  numberList[i];
    }
    
    //input your code
    return 0;
}

void SelectionSort(int numbers[], int size)
{
    int minIndex;
    int minValue;

    for (int i = 0; i<size-1;i++)
    {
        //Keep index of the current min and corresponding element as min
        minValue = numbers[i];
        minIndex = i;
        
        // Find index of smallest remaining element, current MinIndex
        for (int j = i+1; j < size; j++)
        {
            if(minValue > numbers[j])
            {
                minValue = numbers[j];
                minIndex= j;
            }
        }
        swap(numbers[minIndex],numbers[i]);

        //Swapping if necessary
        //input your code

    }
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}