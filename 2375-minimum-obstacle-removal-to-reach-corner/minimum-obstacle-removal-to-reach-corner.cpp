#define p pair<int,pair<int,int>>
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m &&j<n;
    }
    vector<pair<int,int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //dist matrix to keep min obstacle count to reach each cell
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        //minheap-//{min_obstacles_so_far,{i,j}}
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});//top-left (0,0) with 0 obstacles removed
        //dijkstra-0 or 1
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int mindist=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            for(auto d:dirns){
                int nx=x+d.first;
                int ny=y+d.second;
                if(isValid(nx,ny,m,n)){
            //cost to move: grid[nx][ny] is 0 (free) or 1 (obstacle to remove)
                    int newdist=mindist+grid[nx][ny];
                    if(newdist<dist[nx][ny]){
                        dist[nx][ny]=newdist;
                        pq.push({newdist,{nx,ny}});
                    }
                }
            }
        }
        //minimum obstacles to reach bottom-right cell
        return dist[m-1][n-1];
    }
};