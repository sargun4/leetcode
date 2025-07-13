class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 &&j<n;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dirns={
            {-2,-1}, //x-2,y-1 : 2 up,1 left
            {-2,+1}, //x-2,y+1 : 2 up,1 right
            {+2,-1}, //x+2,y-1 : 2 down,1 left
            {+2,+1}, //x+2,y+1 : 2 down,1 right
            {-1,-2}, //x-1,y-2 : 1 up,2 left
            {-1,+2}, //x-1,y+2 : 1 up,2 right
            {+1,-2}, //x+1,y-2 : 1 down,2 left
            {+1,+2}, //x+1,y+2 : 1 down,2 right
        };
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int x=0; int y=0;//start at(0,0)
        for(int i=0;i<n*n;i++){//go over all grid cells-each step of knights tour
            if(grid[x][y]!=i){
                return false;//means that either there is a duplicate or missing no on the grid or that the order of visiting does not match with our expectation.
            }
            vis[x][y]=true;
            for(auto &d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                //in bounds, not yet vis and val= i+1
                if(isValid(nx,ny,n,n) && !vis[nx][ny] && grid[nx][ny]==i+1){
                    x=nx;//update for next row n col
                    y=ny;
                }
            }
        }
        return true;
    }
}; 
// Time : O(N*N)
// Space : O(N*N)
// class Solution {
// public:
// 	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
// 	    int er=TargetPos[0];
//         int ec=TargetPos[1];
//         queue<pair<int,pair<int,int>>> q;
//         vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
// 	    int sr=KnightPos[0];
// 	    int sc=KnightPos[1];
//         if(sr==er && sc==ec)
//             return 0;
//         int steps=0;
// 	    q.push({steps,{sr-1,sc-1}});
//         vis[sr-1][sc-1]=1;
//         int dx[8]={2,2,-2,-2,1,1,-1,-1};
//         int dy[8]={1, -1, 1, -1, 2, -2, 2, -2};
//         while(!q.empty()){
//             auto it=q.front();
//             int steps=it.first;
//             int i=it.second.first;
//             int j=it.second.second;
//             q.pop();
//             if(i==er-1 && j==ec-1){
//                 return steps;
//             }
//             for(int k=0;k<8;k++){
//                 int nx=i+dx[k];
//                 int ny=j+dy[k];
//                 if(nx>=0 && ny>=0 && nx<N && ny<N && vis[nx][ny]==0){
//                     vis[nx][ny]=1;
//                     q.push({steps+1,{nx,ny}});
//                 }
//             }
//             steps++;
//         }
//         return -1;
// 	}
// }; 
