#include <bits/stdc++.h>
using namespace std;

class Solution{ // t= O(N) ,s=O(N)
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> map; //row+col, elemtns
        for(int row=nums.size()-1;row>=0;row--){
            for(int col=0;col<nums[row].size();col++){
                int diag=row+col;
                map[diag].push_back(nums[row][col]);
            }
        }
        vector<int> res;
        int diag =0;
        while(map.find(diag)!=map.end()){
            for(int &num:map[diag]){
                res.push_back(num);
            }
            diag++;
        }
        return res;
    }
};