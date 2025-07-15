class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if(n==0) return s;
        //find longest palindromic prefix;
        int l=0;
        for(int r=n-1;r>=0;r--){
            if(s[r]==s[l]){
                l++;
            }
        } 
        //if whole str palindrome, return original str
        if(l==n){
            return s;
        }
        //get suffix that isnt part of palindromic prefix
        string nonPalindSuffix=s.substr(l);
        string revSuffix=string(nonPalindSuffix.rbegin(),nonPalindSuffix.rend());

        string ans=revSuffix+shortestPalindrome(s.substr(0,l))+nonPalindSuffix;
        return ans;
    }
};