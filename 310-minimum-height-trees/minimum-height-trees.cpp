#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;//undir graph
        vector<int>indeg(n);
        if(n==1)return {0};
        for(auto &edge:edges){ 
            int u=edge[0];
            int v=edge[1];
            indeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1){//leaf nodes
                q.push(i);
            }
        }
        while(n>2){
            int size=q.size();
            n-=size;
            while(size--){
                int u=q.front();
                q.pop();
                for(int &v:adj[u]){
                    indeg[v]--;
                    if(indeg[v]==1){
                        q.push(v);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};