#include<bits/stdc++.h>
using namespace std;

#define BAD 256

//BOYER MOORE ALGORITHM - TC -> AVG CASE - O(N/M) SC -> O(256)


// Filling Bad Char Heuristic
void fillBadChar(int badChar[], int m, string pat) {
    // First fill it with -1
    for(int i=0; i<BAD; i++) 
        badChar[i] = -1;
    
    //Fix the reuqired values
    for(int i=0; i<m; i++) 
        badChar[(int) pat[i]] = i; 
}

//Main Algorithm
void search(string txt, string pat) {
    int n = txt.length(); //Text Length
    int m = pat.length(); //Pattern Length

    int badChar[BAD];
    //Call this func for the preproccessing of Algo
    fillBadChar(badChar, m, pat);

    int s = 0; // S is the shift of pattern in text

    while(s<= (n-m)) { 
        int j=m-1; // J -> Pattern

        while(j>=0 && pat[j] == txt[s+j]) // If char are matching
            j--;

        if(j<0) { //If all char are matched then j is less than 0
            cout<<"Pattern found at "<<s<<endl; //Print ans
            
            /* Shift the pattern so that the next character in text aligns 
            with the last occurrence of it in pattern. The condition s+m < n 
            is necessary for the case when pattern occurs at the end of text */
            s += (s+m < n) ? m-badChar[txt[s+m]]: 1; 
        }
        else
            /* Shift the pattern so that the bad character in text aligns with the last 
            occurrence of it in pattern. The max function is used to make sure that we 
            get a positive shift. We may get a negative shift if the last occurrence of 
            bad character in pattern is on the right side of the current character. */
            s += max(1, j-badChar[txt[s+j]]);
    }
}

int main(){
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    search(txt, pat);
    return 0;
}
