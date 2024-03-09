#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,vector<int>&res,string &labels,vector<int> &count){
        char lbl=labels[curr];
        int countbeforeviscurrchildren=count[lbl-'a'];
        //now explore
        count[lbl-'a']+=1;
        for(int &v:adj[curr]){
            if(v==parent) continue;
            dfs(adj,v,curr,res,labels,count);
        }
        int countafterviscurrchildren=count[lbl-'a'];
        res[curr]=countafterviscurrchildren-countbeforeviscurrchildren;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for (auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res(n,0);
        vector<int> count(26,0);
        dfs(adj,0,-1,res,labels,count);
        return res;
    }
};