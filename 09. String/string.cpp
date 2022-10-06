//  program to reverse a given string.
#include <iostream>
#include <string>
using namespace std;

string reverse_string(string str) {
	string temp_str = str;
	int index_pos = 0;

	for (int x = temp_str.length()-1; x >= 0; x--)
	{
		str[index_pos] = temp_str[x];
		index_pos++;
	}
	return str;
}

int main() 
{
	cout << "Original string: w3resource"; 
	cout << "Reverse string: " << reverse_string("w3resource")<<endl;
	cout << "Original string: Python"<<endl; 
	cout << "Reverse string: " << reverse_string("Python")<<endl;
	return 0;
}
