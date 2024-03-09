#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>&stones,int idx,vector<bool>&vis){
        vis[idx]=true;
        for(int i=0;i<stones.size();i++){
            int r=stones[idx][0];
            int c=stones[idx][1];
            if((vis[i]==false) && (r==stones[i][0] || c==stones[i][1])){
                dfs(stones,i,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n,false);        
        int grps=0;
        for(int i=0;i<n;i++){
            if(vis[i]==true)//skip
                continue;
            dfs(stones,i,vis);
            grps++;
        }
        return n-grps;
    }
};