#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>> adj;
        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxrank =0;
        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
                int irank=adj[i].size();
                int jrank=adj[j].size();
                int rank=irank+jrank;
                if(adj[i].find(j)!=adj[i].end()){
                    rank--;
                }
                maxrank=max(maxrank,rank);
            }
        }
        return maxrank;
    }
};