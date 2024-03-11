#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dirns{{1,0},{0,1},{-1,0},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid) {//bfs
        int m=grid.size();
        int n=grid[0].size();
        queue<vector<int>> q; //q={x,y,steps,currentkeystatus};
        int ctr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){//statring pt
                    q.push({i,j,0,0});
                }else if(grid[i][j]>='a' && grid[i][j]<='f'){//6 keys possible
                    ctr++;//count of key
                }
            }
        }
        int finalkeystatus_deci=pow(2,ctr)-1;
        int vis[m][n][finalkeystatus_deci+1];
        memset(vis, 0, sizeof(vis));
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int i=temp[0];
            int j=temp[1];
            int steps=temp[2];
            int currkeystatus_deci=temp[3];
            if(currkeystatus_deci==finalkeystatus_deci){
                return steps;
            }
            for(auto &dir:dirns){
                int nr=i+dir[0];
                int nc=j+dir[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]!='#'){
                    char ch=grid[nr][nc];
                    if(ch>='A' && ch<='F'){ //lock
                        if(vis[nr][nc][currkeystatus_deci]==0 &&
                        ((currkeystatus_deci>>(ch-'A'))&1) ==1){ //hv the key to this lock
                            vis[nr][nc][currkeystatus_deci]=1;
                            q.push({nr,nc,steps+1,currkeystatus_deci});
                        }
                    }else if(ch>='a' && ch<='f'){ //key
                        int newkeystatus_deci=currkeystatus_deci|(1<<(ch-'a'));
                        if(vis[nr][nc][newkeystatus_deci]==0){
                            vis[nr][nc][newkeystatus_deci]=1;
                            q.push({nr,nc,steps+1,newkeystatus_deci});
                        }
                    }else{//dot
                        if(vis[nr][nc][currkeystatus_deci]==0){
                            vis[nr][nc][currkeystatus_deci]=1;
                            q.push({nr,nc,steps+1,currkeystatus_deci});
                        }
                    }
                }
            }
        }
        return -1;
    }
};