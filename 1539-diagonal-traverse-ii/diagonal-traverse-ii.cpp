#include <bits/stdc++.h>
using namespace std;

// class Solution{ // t= O(N) ,s=O(N)
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         unordered_map<int,vector<int>> map; //row+col, elemtns
//         for(int row=nums.size()-1;row>=0;row++){
//             for(int col=0;col<nums[row].size();col++){
//                 int diag=row+col;
//                 map[diag].push_back(nums[row][col]);
//             }
//         }
//         vector<int> res;
//         int diag =0;
//         while(map.find(diag)!=map.end()){
//             for(int &num:map[diag]){
//                 res.push_back(num);
//             }
//             diag++;
//         }
//         return res;
//     }
// };
class Solution{ // t= O(N) ,s=O(N)
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> res;
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            res.push_back(nums[row][col]);
            if(col==0 && row+1<nums.size()){
                q.push({row+1,col});
            }
            if(col+1<nums[row].size()){
                q.push({row,col+1});
            }
           
        }
        return res;
    }
};