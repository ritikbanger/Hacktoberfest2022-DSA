
// You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

// Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

// Note:

// The frequency of a letter x is the number of times it occurs in the string.
// You must remove exactly one letter and cannot chose to do nothing.
 

// Example 1:

// Input: word = "abcc"
// Output: true
// Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
// Example 2:

// Input: word = "aazz"
// Output: false
// Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
 

// Constraints:

// 2 <= word.length <= 100
// word consists of lowercase English letters only.

class Solution
{
public:
    bool equalFrequency(string word)
    {
        int f[26] = {0};
        for (char c : word)
        {
            f[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (f[i] > 0)
            {
                set<int> st;
                if (f[i] != 1)
                    st.insert(f[i] - 1);
                for (int j = 0; j < 26; j++)
                {
                    if (f[j] == 0 || i == j)
                        continue;
                    st.insert(f[j]);
                }
                if (st.size() == 1)
                    return true;
            }
        }
        return false;
    }
};