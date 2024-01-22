// //KAHN's algo-bfs
// // topo sort-only for DAG
 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        vector<int> indegree(n,0);
        //populate indegree arr and adj  
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){//no incoming edge on that node
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto neigh :adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(res.size()==n){
            return res;
        }else{
            return {};
        }
    }
};