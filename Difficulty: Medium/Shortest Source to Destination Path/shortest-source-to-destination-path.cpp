// User function Template for C++

class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
  vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int,pair<int,int>>> q;//{steps,{x,y}}
        if(A[0][0]==0)
            return -1;
        q.push({0,{0,0}});
        int n=N; int m=M;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;//mrk as vis
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            int steps=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            if(x==X && y==Y){//reached the target cell
                return steps;
            }
            for(auto &d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                if(isValid(nx,ny,n,m) && !vis[nx][ny] && A[nx][ny]!=0){
                    q.push({steps+1,{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};