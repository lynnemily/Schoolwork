#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool passwordGood(string);
bool verifyLength(string);
bool verifyUpper(string);
bool verifyLower(string);
bool verifyDigit(string);


int main()
{
    string input;  // to hold users input
    
    cout << "Please enter a password that is at least 6 characters long "<<endl;
    cout << "and have one upper case letter and one lower case letter " <<endl;
    cout << "with at least one digit" <<endl;
    
    getline (cin, input); 
    
    while ( !passwordGood(input) )
    {
        cout << "Please enter different password: " << endl;
        getline (cin, input);
    }
    
    cout<< "Your password is " << input <<endl;
    
return 0;
}

bool passwordGood(string input)
{
    bool good = true;
    
    if (!verifyLength(input))
    {
        cout  << "Password must be at least 6 characters long"<< endl;
        good = false;
    }
    if (!verifyLower(input))
    {
        cout << "Password must include a lower case letter" << endl;    
        good = false;
    }       
    if (!verifyUpper(input))
    {
        cout << "Password must include a upper case letter" << endl;    
        good = false;
    }       
    if (!verifyDigit(input))
    {
        cout << "You must include one digit" << endl;    
        good = false;
    }
    
    return good;
}       

bool verifyLength(string input)
{
    if (input.length() > 5 )
        return true;
        

    return false;
}


bool verifyLower(string input)
{
    for (int count=0; count < input.size() ; count++ )
    {
        if ( islower(input[count]) )
            return true;
    }
   
    return false;
}

bool verifyUpper(string input)
{
    for (int count=0; count < input.size() ; count++ )
    {
        if ( isupper(input[count]) )
            return true;
    }
    
    return false;
}

bool verifyDigit(string input)
{
    for (int count=0; count < input.size() ; count++ )
    {
        if ( isdigit(input[count]) )
            return true;
    }
    
    return false;
}




