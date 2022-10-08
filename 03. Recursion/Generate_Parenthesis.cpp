/------------------------------------------------------------      Generate Parenthesis     ----------------------------------------------------------------------/

/*

Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()() 
(()) 

*/

/-------------------------------------------------------------------  Solution -------------------------------------------------------------------------------------/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<string> valid;
void generate(string s,int open,int close){
	if(open==0 && close==0){
		valid.push_back(s);
		return ;
	}
	if(close>0){
		if(open<close){
            s.push_back(')');
			generate(s,open,close-1);
			s.pop_back();
		}
	}
	if(open>0){
		s.push_back('(');
		generate(s,open-1,close);
		s.pop_back();
	}
}
int main(){
	int n;
	cin>>n;
	generate("",n,n);
	for(auto l:valid){
		cout<<l<<endl;
	}
}


/--------------------------------------------------------------  Test  Case Passed 100% ----------------------------------------------------------------------------/
[![Screenshot-398.png](https://i.postimg.cc/TPzwP3bm/Screenshot-398.png)](https://postimg.cc/7CNDsDmY)
