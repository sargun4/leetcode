#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>> res=matrix;
        int m=res.size();
        int n=res[0].size();
        for(int j=0;j<n;j++){
            int maxval=INT_MIN;
            for(int i=0;i<m;i++){
                maxval=max(maxval,matrix[i][j]);
            }
            for(int i=0;i<m;i++){
                if(matrix[i][j]==-1){
                    res[i][j]=maxval;
                }
            }
        }
        return res;
    }
};