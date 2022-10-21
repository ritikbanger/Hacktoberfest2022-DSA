class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] && count < 2)
                count++;
            else if (nums[i] == nums[i - 1] && count == 2)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
            else if (nums[i] > nums[i - 1])
            {
                count = 1;
            }
        }
        int k = nums.size();
        return k;
    }
};