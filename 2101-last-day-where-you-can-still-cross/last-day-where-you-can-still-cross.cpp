#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool canWalk(vector<vector<int>>& cells,int row,int col,int dayat){
        vector<vector<bool>>grid(row,vector<bool>(col,0));
        for(int i=0;i<dayat;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>> q;
        for(int c=0;c<col;c++){
            if(grid[0][c]==0){//push all land cells in top row to q 
                q.push({0,c});
                grid[0][c]=1; //then mark as visited
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            if(r==row-1) return true;//able to reach last row
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx<0||ny<0||nx==row||ny==col||grid[nx][ny]==1){
                    continue;
                }
                grid[nx][ny]=1;
                q.push({nx, ny});
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=1;
        int right=cells.size();
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canWalk(cells,row,col,mid)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }

};