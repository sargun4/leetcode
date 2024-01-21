// T-O(2^N)
// S-O(N)
class Solution {
public:
    void solve(int start, vector<int>& candidates, int target, vector<vector<int>>& combs, vector<int>& temp) {
        if (target == 0) {
            combs.push_back(temp);
            return;
        } 
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                temp.push_back(candidates[i]);
                solve(i, candidates, target - candidates[i], combs, temp);
                temp.pop_back();
            }
        }
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        int n = candidates.size();
        vector<int> temp;
        solve(0, candidates, target, combs, temp);
        return combs;
    }
};

// // https://leetcode.com/problems/combination-sum/
// #include <bits/stdc++.h>
// using namespace std;
// // T-O(2^N)
// // S-O(N)
// class Solution {
// public:
//     void solve(int i,vector<int>&candidates,int target,vector<vector<int>> &combs,vector<int> &temp){
//         if (target == 0){ // Base case: if target is reached, add the current combination to combs
//             combs.push_back(temp);
//             return;
//         }
//          // Base case: if all elements are considered
//         if(i==-1){
//             return;
//         }
//         if(candidates[i]>target){ //if curr elmnt is greater than target itself,dont include and move to prev elmnt
//             solve(i-1,candidates,target,combs,temp);
//         }
//         else{
//             //include
//             temp.push_back(candidates[i]);
//             solve(i,candidates,target - candidates[i],combs,temp);
//             //exclude
//             temp.pop_back();
//             solve(i-1,candidates,target,combs,temp);
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> combs;
//         int n=candidates.size();
//         vector<int> temp;
//         solve(n-1,candidates,target,combs,temp);
//         return combs;
//     }
// };