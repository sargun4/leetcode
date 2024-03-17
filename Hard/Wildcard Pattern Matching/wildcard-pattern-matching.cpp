//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isMatch(string pattern, string str, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) // both strings exhausted, match
            return true;
        if (i < 0) // pattern exhausted, but string still has characters
            return false;
        if (j < 0) { // string exhausted, check if remaining pattern characters are all *
            for (int k = 0; k <= i; k++) {
                if (pattern[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        if (pattern[i] == str[j] || pattern[i] == '?')
            return dp[i][j] = isMatch(pattern, str, i - 1, j - 1, dp);
        
        if (pattern[i] == '*')
            return dp[i][j] = isMatch(pattern, str, i - 1, j, dp) || isMatch(pattern, str, i, j - 1, dp);
        
        return dp[i][j] = false;
    }

    bool wildCard(string pattern, string str) {
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return isMatch(pattern, str, n - 1, m - 1, dp);
    }
};


//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends