class Solution {
public:
    bool rec(string&s1,string&s2,string&s3,int i,int j,vector<vector<int>>&dp){
        int k=i+j;
        //all strings fully traversed 
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //if 1st string's char matches in interleaved str, move to next char in s1
        bool a=(i<s1.size() && s3[k]==s1[i]) && rec(s1,s2,s3,i+1,j,dp);
        bool b=(j<s2.size() && s3[k]==s2[j] && rec(s1,s2,s3,i,j+1,dp));

        return dp[i][j]= a || b;
    } 
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(m+n != s3.size()){
            return false;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return rec(s1,s2,s3,0,0,dp);
    }
};