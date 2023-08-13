#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int m=matrix.size();
        int n=matrix[0].size();
        int dir=0;
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;
        vector<int> res;
        while(top <= down && left <= right){
            if(dir==0){
                //left to right
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                //top to down
                for(int i=top;i<=down;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                //right to left
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir==3){
                //down to top
                for(int i=down;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};