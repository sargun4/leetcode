// https://leetcode.com/problems/combinations/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void solve(int start,int &n,int k,vector<int> &temp){
        if(k==0){
            res.push_back(temp);
            return;
        }
        // if(start>n){
        //     return ;
        // }
        for(int i=start;i<=n;i++){ 
            temp.push_back(i);
            solve(i+1,n,k-1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,k,temp);
        return res;
    }
};
// class Solution {
// public:
//     vector<vector<int>> res;
//     void solve(int start,int &n,int k,vector<int> &temp){
//         if(k==0){
//             res.push_back(temp);
//             return;
//         }
//         if(start>n){
//             return ;
//         }
//         temp.push_back(start);
//         solve(start+1,n,k-1,temp);
//         temp.pop_back();
//         solve(start+1,n,k,temp);
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<int> temp;
//         solve(1,n,k,temp);
//         return res;
//     }
// };