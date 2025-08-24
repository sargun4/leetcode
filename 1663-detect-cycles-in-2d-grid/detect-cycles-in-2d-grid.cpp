// Approach:
// - Traverse the grid and run BFS from every unvisited cell.
// - During BFS, we track the parent cell of each visited cell.
// - If we encounter a neighbor that is already visited AND it's not the parent,
//   then a cycle exists.
// - Otherwise, continue BFS until all reachable cells are processed.
// Key Idea
// - The parent check is critical because in an undirected graph (or grid),
//   every visited cell connects back to its parent. That should NOT be mistaken
//   as a cycle. Only when we encounter a previously visited cell that is NOT
//   the parent, it's a real cycle.
using p=pair<int,int>;
class Solution {
public:
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    bool bfs(int x,int y,vector<vector<bool>> &vis,vector<vector<char>>&grid){
        int m=grid.size(); int n=grid[0].size();
        vis[x][y]=true;//starting bfs frm {x,y}
        queue<pair<p,p>> q;//{node,parent}
        q.push({{x,y},{-1,-1}});
        char ch=grid[x][y];
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            int i=curr.first.first;
            int j=curr.first.second;
            int pi=curr.second.first;//parent of i
            int pj=curr.second.second;//parent of j
            for(auto&d:dirns){
                int nx=i+d[0];
                int ny=j+d[1];
//Assuming we've met the boundary conditions and grid character similarity, we next go for checking visited array:
// - If next node is not visited, visit it and put it in queue.
                if(isValid(nx,ny,m,n) && !vis[nx][ny] && grid[nx][ny]==ch){
                    q.push({{nx,ny},{i,j}});
                    vis[nx][ny]=true;
                }
// - Else, if the parent is different than the next node, then return true immidiately
// If the next node is already visited and it is not the parent, 
// then it must be visited by some other node in the bfs, 
// and hence, we've narrowed down the location of the cycle.
        // If we find a visited neighbor that is not the parent, it's a cycle
                else if(isValid(nx,ny,m,n) && vis[nx][ny] && grid[nx][ny]==ch && !(nx==pi && ny==pj)){
                    return true;//cycle found
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(); int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        //run bfs for each cell not vis
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(bfs(i,j,vis,grid)){//check for cycle detction for each node thats not yet been vis
                        return true;//cycle exists
                    }
                }
            }
        }
        return false;
    }
};