'''
https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
'''
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        total_time = 0
        i, j = 0, 0
        
        while i < len(neededTime) and j < len(neededTime):
            curr_total = 0
            curr_max = 0
            
            while j < len(neededTime) and colors[i] == colors[j]:
                curr_total += neededTime[j]
                curr_max = max(curr_max, neededTime[j])
                j += 1

            total_time += curr_total - curr_max
            i = j
        
        return total_time
