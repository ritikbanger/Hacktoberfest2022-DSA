/* Problem : https://leetcode.com/problems/isomorphic-strings/description/

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

For Eg. : 
Input: s = "egg", t = "add"
Output: true

*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
    vector<pair<char , char >> vecs ; 
	vector<pair<char , char >> vect ; 
	int n = s.size() ; 

	// sort(all(vec)) ;
	// for(auto & i: vec ) cout << i.first << "  " << i.second << endl ;  
	for (int i = 0; i < n; ++i)
	{
		vecs.push_back({s[i] , t[i]}) ; 
		vect.push_back({t[i] , s[i]}) ; 
	}


	sort(vecs.begin() , vecs.end());	
    sort(vect.begin() , vect.end());

	// sort(all(vect));

	int first = 1 ; 
	for (int i = 0; i < n-1; ++i)
	{
		if (vecs[i].first == vecs[i+1].first)
		{
			if (vecs[i].second != vecs[i+1].second)
			{
				// cout << "false" << endl ; 
				first = 0 ; 
				// return; 
				break ; 
			}
		}
	}

	// cout << "true" << endl ; 
	int second = 1 ; 

	for (int i = 0; i < n-1; ++i)
	{
		if (vect[i].first == vect[i+1].first)
		{
			if (vect[i].second != vect[i+1].second)
			{
				// cout << "false" << endl ; 
				second = 0 ; 
				// return; 
				break ; 
			}
		}
	}

	// cout << "true" << endl ; 
	if (first == 1 and second == 1)
	{
		return true ;  
	}

	else return false ;  

	

        
    }
};

