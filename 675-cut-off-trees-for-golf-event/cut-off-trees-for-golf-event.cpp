// Collect and Sort Trees: First, we scan the entire forest to find all trees (cells > 1) and store them in a min-heap sorted by height. This ensures we process trees from shortest to tallest.

// BFS Pathfinding: For each pair of consecutive locations (current position → next tree), we use BFS to find the shortest path. BFS guarantees the minimum number of steps since each step has equal weight.

// Validate Reachability: If we can't reach any tree in our sequence, return -1. Otherwise, accumulate the total steps needed.

// Track Position: After cutting each tree, update our current position to that tree's location for the next pathfinding iteration.

// The algorithm essentially becomes: "Find shortest path from start to first tree, then from first tree to second tree, and so on..."
using p=pair<int,pair<int,int>>; //{height[tx][ty],{tx,ty}}
class Solution {
public:
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size();
        int n=forest[0].size();
        if(forest[0][0]==0) return -1;//if starting point is blocked
        //minheap-{ht,{tx,ty}}
        //collect all trees and sort by height in asc order-minheap
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cell_ht=forest[i][j];
                if(cell_ht>1){
                    pq.push({cell_ht,{i,j}});
                }
            }
        }
        int totalSteps=0;
        int sx=0; int sy=0;//start coords
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int curr_ht=curr.first;
            int tx=curr.second.first;//target row
            int ty=curr.second.second;//target col
            //bfs to find shortest distance from (sx, sy) to (tx, ty)
            int minsteps = bfs(forest, sx, sy, tx, ty, m, n);
            if(minsteps==-1) return -1;//unreachable
            totalSteps+=minsteps;
            sx=tx;//move start pt to th tree just cut
            sy=ty;
        }
        return totalSteps;
    }
    
    int bfs(vector<vector<int>>&forest,int sx,int sy,int tx,int ty,int m,int n){
        if(sx==tx && sy==ty) return 0;//alr at target cell
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n, false));
        q.push({sx,sy}); //0 steps
        vis[sx][sy]=true;
        int steps=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto it=q.front(); q.pop();
                int row=it.first;
                int col=it.second;
                for(auto&d:dirns){
                    int nx=row+d[0];
                    int ny=col+d[1];
                    //inbounds, not 0 and unvis cell
                    if(isValid(nx,ny,m,n) && forest[nx][ny]!=0 && !vis[nx][ny]){
                        if(nx==tx && ny==ty){//found target
                            return steps+1;
                        }
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
            steps++;//after processing all curr lvl nodes.
        }
        return -1; //target not reachable
    }
};