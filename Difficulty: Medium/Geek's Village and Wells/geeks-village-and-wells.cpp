//insead o going frm each house to well, take the rev;
// ie house cells reachable frm closest well coords
// /multi src bfs -in queue, push wells as start pts
class Solution {
public:
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    ans[i][j]=0;
                    q.push({i,j});//pushing well coords into q
                }
            }
        }
    // Multi-source BFS: Start from all wells
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front(); q.pop();
                int x=curr.first;
                int y=curr.second;
                for(auto &d:dirns){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    ///inbounds and not unreahbcle cell(N)
                    if(isValid(nx,ny,n,m) && c[nx][ny]!='N'){
                        if(ans[nx][ny]>1+ans[x][y]){
                            ans[nx][ny]=1+ans[x][y];
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='H'){//house
                    if(ans[i][j]==INT_MAX){//wasnt able to reach this house
                        ans[i][j]=-1;//unreachable
                    }else{
                        ans[i][j]*=2;//dist to go to well frm house n back
                    }
                }else if(c[i][j]=='N'||c[i][j]=='.'){
                    ans[i][j]=0;
                }
            }
        }
        return ans;
    }
};