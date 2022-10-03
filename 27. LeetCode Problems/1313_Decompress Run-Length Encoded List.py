'''
https://leetcode.com/problems/decompress-run-length-encoded-list/description/
'''

class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        arr = []
        for i in range(0,len(nums)-1,2):
            freq = nums[i]
            val = nums[i+1]
            for _ in range(freq):
                arr.append(val)
        return arr
