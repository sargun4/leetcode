#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int trytomakeY(vector<vector<int>>& grid,int coly,int colrem){
        int n = grid.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i<=n/2 && (i==j||i+j==n-1))
                  || (i>n/2 && j==n/2)){
                    if(grid[i][j]!=coly) ans++;
                }else{
                    if(grid[i][j]!=colrem) ans++;
                }
            }
        }
        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid){
        int ans=min({trytomakeY(grid,1,0),trytomakeY(grid,1,2),
                     trytomakeY(grid,2,1),trytomakeY(grid,2,0),
                     trytomakeY(grid,0,1),trytomakeY(grid,0,2)});
        return ans;
    }
};

