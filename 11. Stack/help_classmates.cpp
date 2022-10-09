// GeeksForGeeks QUESTION :

/*
Professor X wants his students to help each other in the chemistry lab. 
He suggests that every student should help out a classmate who scored less marks than him in chemistry 
and whose roll number appears after him. 
But the students are lazy and they don't want to search too far. 
They each pick the first roll number after them that fits the criteria. 
Find the marks of the classmate that each student picks.

Note: one student may be selected by multiple classmates.

Example 1:
Input: N = 5, arr[] = {3, 8, 5, 2, 25}
Output: 2 5 2 -1 -1
Explanation: 
    1. Roll number 1 has 3 marks. The first person 
    who has less marks than him is roll number 4, 
    who has 2 marks.
    2. Roll number 2 has 8 marks, he helps student 
    with 5 marks.
    3. Roll number 3 has 5 marks, he helps student 
    with 2 marks.
    4. Roll number 4 and 5 can not pick anyone as 
    no student with higher roll number has lesser 
    marks than them. This is denoted by -1.
Output shows the marks of the weaker student that 
each roll number helps in order. ie- 2,5,2,-1,-1

*/

// { Driver Code Starts
//Initial Template for C++

#include<iostream>
#include<stack>
#include<vector>
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    /*
    // Brute Force Approach
    // Time complexity = O(N^2)
    // Steps:
    // 1) Initialise a vector helper to store the next greater number of arr[i] at each index i
    // 2) Travel arr and for every element at index i
    //      Initialise a bool variable to false
    //      Run a loop from i+1 to n check if the current element is greater than current element, set bool var to true
    //          Then break the loop and store that element in vector helper
    //      If after running through the loop bool variable is false, store -1 in vector helper
    // 3) Return the helper vector

    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
    
        vector<int> helper;
        bool put = false;
        for(int i=0 ; i<n ; i++)
        {
            put = false;
            for(int j=i+1 ; j<n ; j++)
            {
                if(arr[j]<arr[i])
                {
                    put = true;
                    helper.push_back(arr[j]);
                    break;
                }
            }
            if(put == false)
            {
                helper.push_back(-1);
            }
        }
        return helper;
    } */
    

    // Better Approach
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Application of the concept Next Greatest Element
    // Steps:
    // 1) Initialise a vector v to store the next greater number of arr[i] at each index i
    // 2) Create a stack of type integer where we store the smaller element at the top
    // 3) Traverse arr from backwards because when we arrive at a certain index, 
    //    its next greater element will be already in stack
    // 4) For every element at index i
    //      (i) Pop the elements from the stack till we get the greater element on top of the stack from the
    //         current element. The same element will be the NGE for the current element.
    //      (ii) If the stack gets empty while doing the pop operation, then the answer would be -1
    //      (iii) Store the next greater element in the array and push the current element of the array into the stack.
    // 5) Return the vector v.
    vector<int> help_classmate(vector<int> arr, int n) 
    {
         // Your code here
        vector<int> v;
        stack<int> s;
        bool pushed;
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(s.empty() == true)
            {
                v.push_back(-1);
                s.push(arr[i]);
            }
            else
            {
                pushed = false;
                int x;
                while(s.empty()==false )
                {
                    x = s.top();
                    if(x < arr[i])
                    {
                        v.push_back(x);
                        s.push(arr[i]);
                        pushed = true;
                        break;
                    }
                    else
                    {
                        if(s.empty() == false)
                        {
                            s.pop();
                        }
                    }
                }
                if(s.empty()==true && pushed == false)
                {
                    v.push_back(-1);
                    s.push(arr[i]);
                }
                
            
            }
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

  // } Driver Code Ends