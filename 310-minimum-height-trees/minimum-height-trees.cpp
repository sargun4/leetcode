#include<bits/stdc++.h>
using namespace std;
//We perform a layer-by-layer BFS from leaves, removing them repeatedly until we reach the last 1 or 2 nodes, which are the centroids(middlemost ndoes) of the tree and will produce Minimum Height Trees
//Removing all leaves layer by layer eventually will leave the centroids-mhts
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;//undir graph
        vector<int>indeg(n);
        if(n==1)return {0};//base-if theres only 1 node,its the root of MHT
        for(auto &edge:edges){ 
            int u=edge[0];
            int v=edge[1];
            indeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;//queue storing leaf nodes intially
        for(int i=0;i<n;i++){
            if(indeg[i]==1){//leaf nodes
                q.push(i);
            }
        }
        //each itern removes curr layer of leaves
        //stop when <=2 nodes are left- centroids
        while(n>2){
            int size=q.size();
            n-=size;//removing size nodes frm graph
            while(size--){
                int u=q.front();
                q.pop();
                for(int &v:adj[u]){
                    indeg[v]--;//remove edge u-v
                    if(indeg[v]==1){//if v becomes leaf
                        q.push(v);
                    }
                }
            }
        }
        //remaing 1 or 2 nodes are MHT roots
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};