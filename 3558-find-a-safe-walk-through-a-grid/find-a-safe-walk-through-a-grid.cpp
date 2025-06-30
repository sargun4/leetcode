class Solution {
public:
// If the next cell is an obstacle, health is reduced, and if it's not, health remains the same.
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>>dirns={{1,0},{0,1},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        //maxheap-{maxhealth,{row,col}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        if(grid[0][0]==1){//top leftcell itself is an obstacle
            pq.push({health-1,{0,0}});
        }else{
            pq.push({health,{0,0}});
        }
        vis[0][0]=true;
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int currhealth=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;

            if(x==m-1 && y==n-1){//reached bottom right cell
                if(currhealth>=1) return true;//reach it w a health value of >=1
            }
            
            for(auto d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                if(isValid(nx,ny,m,n) && !vis[nx][ny]){
                    if(grid[nx][ny]==0){//not obstacle, so no decrmnt in health
                        vis[nx][ny]=true;
                        pq.push({currhealth,{nx,ny}});
                    }else{//obstcle
                        vis[nx][ny]=true;
                        pq.push({currhealth-1,{nx,ny}});
                    }
                }
            }
        }
        return false;
    }
};