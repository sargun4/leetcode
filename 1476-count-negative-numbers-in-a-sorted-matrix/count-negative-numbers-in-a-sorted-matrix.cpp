// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int res=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]<0){
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(auto &row:grid){
            int idx=upper_bound(begin(row),end(row),0,greater<int>())-begin(row);
            res+=(n-idx);            
        }
        return res;
    }
};

