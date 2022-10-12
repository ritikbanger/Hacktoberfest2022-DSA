// Random Password Generator Using String
// A program that generates a random password of min length 6 and
// max length 12 automatically, that has all fields checked
// i.e. has both upper case and lower case letters, numbers
// and even special characters as a combination
#include <bits/stdc++.h>
using namespace std;

// Function to generate random password string
string gen_random()
{
    // to change random value with time
    srand(time(0));
    int minlen = 6, maxlen = 12;
    // length to be used
    int uselen = (rand() % (maxlen - minlen + 1)) + minlen;

    string s;
    // all characters that can form the password
    string alphanum =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@!,.*;";

    for (int i = 0; i < uselen; ++i)
    {
        s += alphanum[rand() % (alphanum.length() - 1)];
    }
    // returning the string formed
    return s;
}

// boolean function to check if the automatically generated password string
// passes all fields of being an accepted password
bool checkPass(string str)
{
    int n = str.length(), fu = -1, fs = -1, fn = -1;

    // Check for upper case character
    for (int i = 0; i < n; i++)
    {
        if (isupper(str[i]))
        {
            fu = 1;
        }

        // Check for special character
        if (str[i] == '@' or str[i] == '!' or str[i] == ',' or str[i] == '.' or str[i] == '*' or str[i] == ';')
        {
            fs = 1;
        }

        // Check for number
        if (str[i] - '0' >= 0 and str[i] - '0' <= 9)
        {
            fn = 1;
        }
    }
    // If all conditions true, return true else return false
    if (fu == 1 and fs == 1 and fn == 1)
        return true;
    else
        return false;
}

// Main method
int main()
{
    string str = gen_random();

    // Keep on generating password strings, until all checks have not passed
    while (!checkPass(str))
    {
        str = gen_random();
    }
    // Printing random password generated
    cout << "Automatically Generated Random Password : " << str << endl;
    return 0;
}