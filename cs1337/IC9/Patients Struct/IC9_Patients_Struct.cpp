#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define INFONUM 255

// patients structure definition
struct Patients 
{
    int ID;
    string FN;
    string LN;
    int BPU;
    int BPL;
    int Pulse;
    // fields
};

int main()
{
   //open the input file for reading.
   ifstream inputfile;
   string fname;
   cout<<"Enter filename: \n";
   cin>>fname;
   inputfile.open(fname);
   
   if (!inputfile) 
   {
   cout<<"Could not open file\n";
   cout<<"Exiting" << endl;
   return 0;
   }
    // Read the header line and parse using istringstream Use setw(10) for First and last name.
    //Setw(4) for  for ID and other vitals   
   string header;
   getline(inputfile, header);

   
   Patients array[INFONUM];
   int count = 0;
   while (inputfile >> array[count].ID >> array[count].FN >> array[count].LN >> array[count].BPU >> array[count].BPL >> array[count].Pulse) 
   {
        count++;
        if (count >= INFONUM) break; 
   }
   
    //Dynamically create Patients array   
   Patients *list = new Patients[count];
       // Read the values into array of structures
   for(int i = 0; i < count; i++)
   {
       list[i] = array[i];
   }
  
   // Display the values
   //Use setw(10) for First and last name, Setw(4) for ID and other vitals
    cout<<left<<setw(4)<<"ID"<<setw(10)<<"FN"<<setw(10)<<"LN"<<setw(4)<<"BPU"<<setw(4)<<"BPL"<<setw(4)<<"Pulse\n";
    for(int i = 0; i < count; i++)
    {
        cout<<setw(4)<<list[i].ID<<setw(10)<<list[i].FN<<setw(10)<<list[i].LN<<setw(4)<<list[i].BPU<<setw(4)<<list[i].BPL<<setw(4)<<list[i].Pulse<<endl;
    }




    inputfile.close();
    //close the file
   
    delete[] list;
    //delete the pointer
    
    return 0;
}//end of main

//patientsinfo.txt
