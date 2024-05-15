class Solution {
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    bool bfs(vector<vector<int>> &dist, int sf){
        if(dist[0][0]<sf) return false;
        int n=dist.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        q.push({0, 0});
        vis[0][0]=true;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1 && y==n-1) return true;
            for(int k=0; k<4; k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]>=sf && !vis[nx][ny]){
                    q.push({nx, ny});
                    vis[nx][ny]=true;
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    dist[i][j]=0;
                    q.push({i, j});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny])
                    {
                        q.push({nx, ny});
                        vis[nx][ny]=true;
                        dist[nx][ny]=1+dist[x][y];
                    }
                }
            }
        }
        int low=0, high=1e9, ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(bfs(dist, mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};