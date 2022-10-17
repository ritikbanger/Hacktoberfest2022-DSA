#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
// Simple Brain Quiz Game in CPP
void Math_Quiz()
{
    cout << "Welcome TO Brain Quiz 1" << endl
         << endl;
    cout << "********************************************" << endl
         << endl;
    int choice;
    cout << "\t\t MATH TEST ' 4+5 = ? '" << endl
         << endl;
    cout << "Select Correct Options:  " << endl;
    cout << "1. 4+5 = 10" << endl;
    cout << "2. 4+5 = 12" << endl;
    cout << "3. 4+5 = 12" << endl;
    cout << "4. 4+5 = 09" << endl;
    cout << "Enter Your Choice: " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Incorrect Option";
        break;
    case 2:
        cout << "Incorrect Option";
        break;
    case 3:
        cout << "Incorrect Option";
        break;
    case 4:
        cout << "Correct Option";
        break;
    default:
        cout << "Invalid Choice Please Select Correct Opt.(1 to 4)";
        break;
    }
}
void Computer_Quiz()
{
    cout << "\n\nWelcome TO Brain Quiz 2" << endl
         << endl;
    cout << "********************************************" << endl
         << endl;
    int choice;
    cout << "\t\t SPELLING TEST ' CAMPOTER ' " << endl
         << endl;
    cout << "Select Correct Options:  " << endl;
    cout << "1. COUMPUTER" << endl;
    cout << "2. COMPUTER" << endl;
    cout << "3. COMPUTAR" << endl;
    cout << "4. COMPATER" << endl;
    cout << "Enter Your Choice: " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Incorrect Option";
        break;
    case 2:
        cout << "Correct Option";
        break;
    case 3:
        cout << "Incorrect Option";
        break;
    case 4:
        cout << "Incorrect Option";
        break;
    default:
        cout << "Invalid Choice Please Select Correct Opt.(1 to 4)";
        break;
    }
}
int main()
{
    string n;
    cout << "Enter Your Name: ";
    getline(cin, n);
    system("cls");
    cout << n << endl
         << endl;
    Math_Quiz();
    Computer_Quiz();
    return 0;
}