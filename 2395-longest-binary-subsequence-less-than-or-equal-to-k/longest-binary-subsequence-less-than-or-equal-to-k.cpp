class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        long long power=1;//2*0;
        int len=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                len++;
            }else if(power<=k){
                k-=power;
                len++;
            }
            if(power<=k){
                power=power*2;
            }
        }
        return len;
    }
};