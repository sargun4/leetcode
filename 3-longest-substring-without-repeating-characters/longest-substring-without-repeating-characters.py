class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(len(s)==0):
            return 0
        map={}
        maxlen=start=0
        for i in range(len(s)):
            if(s[i] in map and start<=map[s[i]]):
                start=map[s[i]]+1
            else:
                maxlen=max(maxlen,i-start+1)
            map[s[i]]=i
        return maxlen