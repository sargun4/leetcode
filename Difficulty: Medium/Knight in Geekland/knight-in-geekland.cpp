typedef pair<int,int> p;
class Solution {
public:
    bool isValid(int i,int j,int n,int m){//inbounds check
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<vector<int>> dirns={//8possible knight moves 
        {1,2},
        {2,1},
        {-1,2},
        {2,-1},
        {1,-2},
        {-2,1},
        {-1,-2},
        {-2,-1},
    };
    int knightInGeekland(int start_x, int start_y, vector<vector<int>> &arr) {
        int n=arr.size(); int m=arr[0].size();
        queue<p> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> points;//to store pts for ith step
        int steps=0;
        q.push({start_x,start_y});
        vis[start_x][start_y]=true;
        //bfs
        while(!q.empty()){
            int qsize=q.size();
            //resize pts vector to include curr step
            if (points.size() <= steps) points.push_back(0);

            while(qsize--){
                auto curr=q.front(); q.pop();
                int x=curr.first;
                int y=curr.second;
                //add pts to curr cell
                points[steps]+=arr[x][y];
                for(auto&d:dirns){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(isValid(nx,ny,n,m) && !vis[nx][ny]){
                        vis[nx][ny]=true;
                        q.push({nx,ny});//add nxt lvl to q
                    }
                }
            }
            steps++;
        }
        int ans=0;
        int maxi=INT_MIN;
        for(int i = points.size() - 1;i>=0;i--){
            int jump_to = i + points[i];
            if (jump_to < points.size()) {
                points[i] += points[jump_to];
            }
            if(points[i]>=maxi){
                maxi=points[i];
                ans=i;
            }
        }
        return ans;
    }
};