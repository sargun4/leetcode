// //memo
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int n;
//     int dp[1001][1001];
//     int lis(vector<vector<int>>&pairs,int previdx,int curridx){
//         if(curridx==n) return 0;
//         if(previdx!=-1 && dp[previdx][curridx]!=-1){
//             return dp[previdx][curridx];
//         }
//         int taken=0;
//         if(previdx==-1||pairs[curridx][0]>pairs[previdx][1])
//             taken=1+lis(pairs,curridx,curridx+1);
//         int nottaken=lis(pairs,previdx,curridx+1);
//         if(previdx!=-1)
//             dp[previdx][curridx]=max(taken,nottaken);
//         return max(taken,nottaken);
//     }

//     int findLongestChain(vector<vector<int>>& pairs) {
//         memset(dp,-1,sizeof(dp));
//         n=pairs.size();
//         sort(begin(pairs),end(pairs));
//         return lis(pairs,-1,0);        
//     }
// };

//tab
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       int n=pairs.size();
       sort(begin(pairs),end(pairs));
       vector<int> t(n,1);
       int maxL=1;
       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(pairs[j][1]<pairs[i][0]){
                t[i]=max(t[i],t[j]+1);
                maxL=max(maxL,t[i]);
            }
          }
       }
       return maxL;
    }
};