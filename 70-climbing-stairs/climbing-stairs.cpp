// #include <bits/stdc++.h>
// using namespace std;
// //memo
// vector<int> dp(46,-1);
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(dp[n]!=-1) return dp[n];
//         if(n<=2){
//             return dp[n]=n;
//         }
//         return dp[n]=climbStairs(n-1)+climbStairs(n-2);
//     }
// };

// //Tabulation-bottom up
// // arr[i]- no of ways to climb i stairs
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=2){
//             return n;
//         }
//         vector<int> arr(n+1,0);
//         arr[1]=1;
//         arr[2]=2;
//         for(int i=3;i<=n;i++){
//             arr[i]=arr[i-1]+arr[i-2];
//         }
//         return arr[n];
//     }
// };


class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int a=1,b=2,c=3;
        for(int i=3;i<=n;i++){
            c=a+b;
            int tempb=b;
            b=c;
            a=tempb;
        }
        return c;
    }
};