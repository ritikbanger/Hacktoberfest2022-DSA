// implementaion of boyer moore algorithm
// real life uses of boyer moore algorithm:
/*
1. spell checkers
2. text editors
3. DNA sequencing
4. web search
5. pattern matching
6. bioinformatics
7. Big data
*/

#include <bits/stdc++.h>
using namespace std;

// bad character heuristic
void badCharHeuristic(string pattern, int patternLength, unordered_map<char, int> &badChar)
{
    for (int i = 0; i < patternLength - 1; i++)
        badChar[pattern[i]] = i;
}

// boyer moore algorithm
void boyerMoore(string text, string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();

    unordered_map<char, int> badChar;

    badCharHeuristic(pattern, patternLength, badChar);

    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (textLength - patternLength))
    {
        int j = patternLength - 1;

        // Keep reducing index j of pattern while characters of pattern and text are matching at this shift s
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        // If the pattern is present at current shift, then index j will become -1 after the above loop
        if (j < 0)
        {
            cout << "Pattern found at index " << s << endl;

            // Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern.
            // The condition s + patternLength < textLength is necessary for the case when pattern occurs at the end of text
            s += (s + patternLength < textLength) ? patternLength - badChar[text[s + patternLength]] : 1;
        }
        else
            // Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern. The max function is used to make sure that we get a positive shift. We may get a negative shift if the last occurrence of bad character in pattern is on the right side of the current character.
            s += max(1, j - badChar[text[s + j]]);
    }
}

int main()
{
    string text = "happyhacking";
    string pattern = "hack";
    boyerMoore(text, pattern);
    return 0;
}