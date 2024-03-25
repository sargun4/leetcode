
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int res=-1;
    void dfs(int u,vector<int>& edges,vector<bool>&vis,vector<int>&count,vector<bool>&inrec){
        if(u!=-1){
            vis[u]=true;
            inrec[u]=true;
            int v=edges[u];
            if(v!=-1 && !vis[v]){
                count[v]=count[u]+1;
                dfs(v,edges,vis,count,inrec);
            }else if(v!=-1 && inrec[v]==true){//cycle exists  but it is in recursion
                res=max(res,count[u]-count[v]+1);
            }
            inrec[u]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(n,false);
        vector<bool> inrecursion(n,false);
        vector<int> count(n,1);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,edges,vis,count,inrecursion);
            }
        }
        return res;
    }
};