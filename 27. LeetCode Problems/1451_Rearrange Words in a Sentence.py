'''
https://leetcode.com/problems/rearrange-words-in-a-sentence/description/
'''

class Solution:
    def arrangeWords(self, text: str) -> str:
        arr = text.lower().split()
        arr.sort(key = lambda x: len(x))
        text = ""
        text += arr[0].capitalize()+' '
        for i in range(1,len(arr)):
            text += arr[i]+' '
        return text[:-1]
