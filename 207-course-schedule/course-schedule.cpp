#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //kahns algo- bfs- topo sort for DAG only
    bool toposort(unordered_map<int,vector<int>> &adj,int n,vector<int>&indegree){
        queue<int> q;
        int ctr=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) { 
                q.push(i);
                ctr++;
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int &v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    ctr++;
                }
            }
        }
        if(ctr==n){ //visited all nodes-no cylce
            return true;
        }
        return false;//cycle present in graph
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0); //kahns algo
        for (auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        //if cycle present, no possible orderings
        return toposort(adj,n,indegree);
    }
};
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites) {
//         vector<int> adj[numCourses];
//         for(auto it:prerequisites){
//             adj[it.first].push_back(it.second);
//         }
//         // int indegree[numCourses]={0};
//         vector<int> indegree(numCourses, 0); 
//         for(int i=0;i<numCourses;i++){
//             for(auto it:adj[i]){
//                 indegree[it]++;
//             }
//         }
//         queue<int> q;
//         for(int i=0;i<numCourses;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int> topo;
//         //O(V+E)
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto it:adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0) q.push(it);
//             }
//         }
//         if(topo.size()==numCourses) return true;
//         return false;
//     }
// };