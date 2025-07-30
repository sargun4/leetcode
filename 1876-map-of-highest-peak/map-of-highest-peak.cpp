// For every cell in the grid, we calculate its smallest distance to any water cell and assign that value as its height.
// Heights increase smoothly from water cells, ensuring the highest peak is at the farthest distance from all water cells.
// This can be visualized as a "ripple effect" where water cells propagate their distances outward, assigning heights to nearby land cells.
//Multi src bfs frm water cells(0) to get shortest dist to land cells
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;//{i,j};
        //goin over all cells in mat and mark ht of water cells as 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){//water cell
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int ht=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front(); q.pop();
                int x=curr.first;
                int y=curr.second;
                for(auto&d:dirns){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    //in bounds and not yet vis
                    if(isValid(nx,ny,m,n) && ans[nx][ny]==-1){
                        ans[nx][ny]=ht;
                        q.push({nx,ny});
                    }
                }
            }
            ht++;//next lvl
        }
        return ans;
    }
};