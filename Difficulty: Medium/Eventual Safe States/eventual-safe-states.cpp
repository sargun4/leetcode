#include <bits/stdc++.h>
using namespace std;
// A node is eventually safe if every possible path starting from 
//that node leads to a terminal node (a node with no outgoing edges).
//  Nodes that are part of a cycle or lead into cycles are unsafe.
// Reverse the graph and use Kahn's Algorithm to perform topological sorting.
// Nodes with no outgoing edges in the reversed graph are safe.

class Solution {
    public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);//in-degree of each node in reversed graph
        vector<int> ans;//store safe nodes
        vector<int> adj1[V];//rev graph
        //1. rev the graph n calc indegrees
        for(int i=0;i<V;i++){
           for(auto it:adj[i]){
               adj1[it].push_back(i);//original outgoing edge becomes incoming in reversed graph
               indegree[i]++;
           }
        }
       //2. push all terminal nodes(with indegree 0 in rev graph) to queue 
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //KAHN's algo-bfs toposort
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);//node is safe
            for(auto it:adj1[node]){//for all og parents in rev graph
                indegree[it]--;//reduce degree
                if(indegree[it]==0){//if now safe,add to q
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


