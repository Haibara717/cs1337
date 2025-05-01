#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

// Students are required to implement these functions
bool isValidPrice(string);
string tokenize(string & s);
bool isAlnumString(const string &s); 
bool isOnlydigit(const string &s); 
// code the rest

int main()
{
    string filename;
    cout<<"Enter input file:";
    cin>>filename;
    
    ifstream inFile(filename);
    if (!inFile) 
    {
        cout<< "Error opening file!" << endl;
        return 1;
    }
    
    string line;
    bool valid = true;
    
    cout << "\nChecking " << filename << endl;
    cout << string(9 + filename.length(), '-') << endl;
    cout<<endl;
    
    int lineNum = 0;
    while (getline(inFile, line)) 
    {  
        lineNum++;
        string temp = line; 
        int tokenIndex = 1;
        
    
        string plu = tokenize(temp);
        if (plu.empty()) 
        {
            cout << "Plu is invalid, record has missing items" << endl;
            valid = false;
            cout << endl;
            break;
        }
        
        cout << "Token #" << tokenIndex++ << " is " << plu << ", PLU is ";
        if (plu.length() != 4 || !isAlnumString(plu)) 
        {
            cout << "invalid" << endl;
            valid = false;
            cout<<endl;
            break;
        } 
        else 
        {
            cout << "valid" << endl;
        }
        
        
        string name = tokenize(temp);
        if (name.empty()) 
        {
            cout << "Name is invalid, record has missing items" << endl;
            valid = false;
            cout << endl;
            break;
        }
        
        cout << "Token #" << tokenIndex++ << " is " << name << ", Product name is ";
        if (name.empty() || !isalpha(name[0])) 
        {
            cout << "invalid" << endl;
            valid = false;
            cout<<endl;
            break;
        } 
        else 
        {
            cout << "valid" << endl;
        }
        
        
        string salesType = tokenize(temp);
        if (salesType.empty()) 
        {
            cout << "SalesType is invalid, record has missing items" << endl;
            valid = false;
            cout << endl;
            break;
        }
        
        cout << "Token #" << tokenIndex++ << " is " << salesType << ", Sales type is ";
        if (salesType != "0" && salesType != "1" && salesType.length() != 1) 
        {
            cout << "invalid" << endl;
            valid = false;
            cout<<endl;
            break;
        } 
        else 
        {
            cout << "valid" << endl;
        }
        
        
        string price = tokenize(temp);
        if (price.empty()) 
        {
            cout << "Price is invalid, record has missing items" << endl;
            valid = false;
            cout << endl;
            break;
        }
        
        cout << "Token #" << tokenIndex++ << " is " << price << ", Price is ";
        if (!isValidPrice(price)) 
        {
            cout << "invalid" << endl;
            valid = false;
            cout<<endl;
            break;
        } 
        else 
        {
            cout << "valid" << endl;
        }
        
        
        string inventory = tokenize(temp);
        if (inventory.empty()) 
        {
            cout << "Inventory is invalid, record has missing items" << endl;
            valid = false;
            cout << endl;
            break;
        }
        
        cout << "Token #" << tokenIndex++ << " is " << inventory << ", Inventory is ";
        if (inventory.empty() || !isOnlydigit(inventory)) 
        {
            cout << "invalid" << endl;
            valid = false;
            cout<<endl;
            break;
        } 
        else 
        {
            cout << "valid" << endl;
        }
        
        string extraToken = tokenize(temp); 
        if (!extraToken.empty()) 
        {
            cout << "Token #" << tokenIndex++ << " is " << extraToken << ", Too many items in record" << endl;
            valid = false;
            cout << endl;
            break;
        }
        cout<<endl;
    }
    cout << "######## " << filename << " has ";
    if (valid) 
    {
        cout << "valid content ########" << endl;
    } 
    else 
    {
        cout << "invalid content ########" << endl;
    }
    
    return 0;
}

string tokenize(string & s)
{
    int start = 0;
    int sz = s.length();
    
    while(start < sz && isspace(s[start])) 
    {
        start++;
    }
    
    if (start == sz) 
    return "";
    
    int end = start;
    while(end < sz && !isspace(s[end]))
    {
        end++;
    }
    
    string token = s.substr(start, end - start);
    s = s.substr(end);
    
    return token;
}
bool isAlnumString(const string &s) 
{
    for (char c : s) 
    {
        if (!isalnum(c)) 
        {
            return false;  
        }
    }
    
    return true;  
}
bool isOnlydigit(const string &s) 
{
    for (char c : s) 
    {
        if (!isdigit(c)) 
        {
            return false;  
        }
    }
    return true;  
}
bool isValidPrice(string price)
{
    if (price.empty()) 
    {
        return false;
    }
    
    int length = price.length();
    int dotCount = 0;
    
    for(int i = 0; i < length; i++)
    {
        if (price[i] == '.') 
        {
            dotCount++;
            if (dotCount > 1) 
            {
                return false;
            }
            if (i == 0 || i == length - 1) 
            {
                return false; 
            }
        } 
        else if (!isdigit(price[i])) 
        {
            return false; 
        }
    }
    
    int dotPos = price.find('.');
    int sz = price.size();
    if (dotPos + 3 < sz) 
    {
        return false;
    }

    return true;
}
