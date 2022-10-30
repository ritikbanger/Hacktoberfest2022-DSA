class Solution {
public:
    int longestPalindrome(string inputString) {
      unordered_map<char, int> freq;
      int count = 0, maxOddFreq = INT_MIN;
      bool isFirstOccOfOdd = false;


      for (int i = 0; i < inputString.size(); ++i)
      {
          if (freq.find(inputString[i]) == freq.end())
          {
              freq.insert(make_pair(inputString[i], 1));
          }
          else
          {
              freq[inputString[i]]++;
          }
      }

      for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it)
      {
          if ((*it).second % 2 == 0)
          {
              count += (*it).second;
          }
          else
          {
              if (isFirstOccOfOdd == false)
              {
                  count += (*it).second;
                  isFirstOccOfOdd = true;
              }
              else
              {
                  count += (*it).second - 1;
              }
          }
      }
      
      return count;
    }
};
