#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges){
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
		vector<int> indeg(n, 0);
		for (int i = 0; i < n; i++){
			for (auto adjnode : adj[i]){
				indeg[adjnode]++;
			}
		}
        // Topological sort using BFS
		queue<int> q;
		for (int i = 0; i < n; i++){
			if (indeg[i] == 0)
				q.push(i);
		}
		vector<int> toposort;
		vector<vector<int>> ans(n);
		while (!q.empty()){
			int node = q.front();
			q.pop();
			toposort.push_back(node);
			for (auto adjnode : adj[node]){
				indeg[adjnode]--;
                // Add current node as ancestor
				if (find(ans[adjnode].begin(), ans[adjnode].end(), node) == ans[adjnode].end())
					ans[adjnode].push_back(node);
                // Add all ancestors of current node to child
				for (int i = 0; i < ans[node].size(); i++){
					if (find(ans[adjnode].begin(), ans[adjnode].end(), ans[node][i]) == ans[adjnode].end()){
						ans[adjnode].push_back(ans[node][i]);
					}
				}
				if (indeg[adjnode] == 0){
					q.push(adjnode);
				}
			}
		}
		for (int i = 0; i < n; i++){
			sort(ans[i].begin(), ans[i].end());
		}
		return ans;
	}
}; 
// Create adjacency list for given graph.
// Perform topological sort.
// While performing toposort for each adjacent node insert its parent in ans and insert parent's parents in ans. (Check if they are not already present)
// sort each vector in ans.
// return ans.

// class Solution {
// public:
//     vector<vector<int>> getonlyTheParents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> ans;
//         unordered_map<int,vector<int>> parents;
//         for(auto it:edges){
//             int u=it[0];
//             int v=it[1];
//             parents[v].push_back(u);
            
//         }
//         for(int i=0;i<n;i++){
//             vector<int> res;
//             if(parents[i].size()==0){
//                 res={};
//             }else{
//                 res=parents[i];
//             }
//             ans.push_back(res);
//         }
//         return ans;
//     }
// };