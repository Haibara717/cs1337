#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    string article[] = { "the", "a", "one", "some", "any" };
    string noun[] = { "boy", "girl", "dog", "town", "car" };
    string verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
    string preposition[] = { "to", "from", "over", "under", "on" };
    
    int seed; 
    cout << "Enter a seed Value: \n";
    cin >> seed;
    srand(seed);
    for(int j = 0; j<8;j++)
    {
        string sentence = ""; // completed sentence
        int sequences[6];
        for(int i = 0 ; i < 6; i++)
        {
            sequences[i]=rand()%5;
        }
        sentence.append(article[sequences[0]]);
        sentence.append(" ");
        sentence.append(noun[sequences[1]]);
        sentence.append(" ");
        sentence.append(verb[sequences[2]]);
        sentence.append(" ");
        sentence.append(preposition[sequences[3]]);
        sentence.append(" ");
        sentence.append(article[sequences[4]]);
        sentence.append(" ");
        sentence.append(noun[sequences[5]]);
        sentence.append(".");
        
        
        if (!sentence.empty()) 
        {
            sentence[0] = toupper(sentence[0]);
        }
        
        cout<<sentence<<endl;
    }
   return 0;
    // create 8 sentence
    
    
    
    
}
