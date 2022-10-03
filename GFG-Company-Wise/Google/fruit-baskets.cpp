/*
    1 2 1 2 2 2 4 5 4 5 3 3 3 3 3 5
    0 1 2 3
    longest subarray with only 2 unique elements

    // binary search
    // we have a range on answer, 1 <= answer <= arr.size()
    
    // NlogN
*/

class Solution
{
    bool check(int subarray_size, vector<int> &fruits)
    {
        // create sliding window of subarray_size
        // if we can create any window [i...j] such that it has only 2 unique elements
        // we return true
        // else false
        unordered_map<int, int> fz; // frequency array
        // default value of each element in unordered map = 0

        for (int i = 0; i < fruits.size(); ++i)
        {
            if (i >= subarray_size)
            {
                // erase first element of window
                if (--fz[fruits[i - subarray_size]] == 0)
                    fz.erase(fruits[i - subarray_size]);
            }

            fz[fruits[i]]++;

            // check map size when we are on last element
            if (i >= subarray_size - 1)
            {
                if (fz.size() <= 2)
                    return true;
            }
        }

        return false;
    }

public:
    int totalFruit(vector<int> &fruits)
    {
        int start = 2, end = fruits.size(), res = 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (check(mid, fruits))
            {
                res = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return res;
    }
};

// How can we make this more efficient
// O(N) ??
// sliding window problem

/*
    1 2 1 2 2 2 4 5 4 5 3 3 3 3 3 5
    0 1 2 3
    longest subarray with only 2 unique elements

    // sliding window!
    
    in largest subarray questions, do not decrease the window size ever, unnecessary computations
*/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int i = 0, j = 0;
        unordered_map<int, int> fz;

        for (; j < fruits.size(); ++j)
        {
            ++fz[fruits[j]];

            if (fz.size() > 2)
            {
                if (--fz[fruits[i]] == 0)
                    fz.erase(fruits[i]);
                ++i;
            }
        }

        return j - i;
    }
};