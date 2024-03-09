#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> adj;
        vector<int> indeg(n,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adj[u].push_back(v);
            indeg[v]++; //incoming edge toward v
        }
        queue<int> q;
        vector<int> maxtime(n,0);
        for(int i=0;i<n;i++){
            if(indeg[i]==0){ 
                q.push(i);
                maxtime[i]=time[i];
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                maxtime[v]=max(maxtime[v],maxtime[u]+time[v]);
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return *max_element(begin(maxtime), end(maxtime));
    }
};