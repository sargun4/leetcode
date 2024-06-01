class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=int(s.length());
        int ans=0;
        unordered_map<char,int> map;
        for(int j=0,i=0;j<n;j++){
            if(map[s[j]]>0){//repeated chr
                i=max(map[s[j]],i);
            }
            ans=max(ans,j-i+1);
            map[s[j]]=j+1;
        }
        return ans;
    }
};