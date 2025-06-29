class Solution {//tab
public:
    int numTrees(int n) {
        vector<int> dp(n+1);//dp[i]=no of unique BSTs using i nodes
        dp[0]=dp[1]=1;//basecase:0 or 1 node = only 1 bst
        for(int i=2;i<=n;i++) 
            for(int j=1;j<=i;j++)
                //for each j from 1 to i:
                // -j as root
                // -left subtree has (j-1) nodes
                // -right subtree has (i-j) nodes
                dp[i]+=dp[j-1]*dp[i-j];
        return dp[n];
    }
};
//memo
// class Solution {
// public:
//     int dp[20]{};
//     int numTrees(int n) {
//         if(n <= 1) return 1;
//         if(dp[n]) return dp[n];
//         for(int i = 1; i <= n; i++) 
            // int left=numTrees(i-1);//trees in left subtree
            // int right=numTrees(n-i);//trees in right subtree
            // dp[n]+=left*right;//total combinations
//         return dp[n];
//     }
// };