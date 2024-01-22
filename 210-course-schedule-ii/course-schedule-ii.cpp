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
        // Push nodes with indegree 0 to the queue
        for(int i=0;i<n;i++){
            if(indegree[i]==0){//no incoming edge on that node
                q.push(i);
            }
        }
        //bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
        // Update indegrees and enqueue neighbors with indegree 0
            for(auto neigh :adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        // Check if a valid ordering exists
        if (res.size() == n) {
            return res;  // Valid ordering exists
        } else {
            return {};  // Impossible to finish all tasks
        }
    }
};
// //dfs
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         //Initializing a 2d graph , result vector and indegree array
//         vector<vector<int>> graph(numCourses);
//         vector<int> result, indegree(numCourses);
        
//         //Indegree
//         for(auto& prereq : prerequisites)
//             graph[prereq[1]].push_back(prereq[0]),
//             indegree[prereq[0]]++;
        
//         //dfs call
//         function<void(int)> dfs = [&](int current) {
//             //Adding the current course into the result 
//             result.push_back(current);            
//             //Making sure that the current course that we added is marked as visited
//             indegree[current] = -1;                     
            
//             //if any next course has a indegree of 0 ie if it has no prerequisites requirement than make dfs call for that course
//             for(auto nextCourse : graph[current])          
//                 if(--indegree[nextCourse] == 0)     
//                     dfs(nextCourse);                
//         };
        
//         // If the indegree becomes 0 of a course then again add them into DFS and start DFS call from that course .
//         for(int i = 0; i < numCourses; i++)
//             if(indegree[i] == 0) dfs(i);                   
        
//         //In the end return `result` if it contains all `numCourses` else return  []
//         if(size(result) == numCourses) return result;
//         return {};
//     }
// };
// // //dfs
// // class Solution {
// // public:
// //     vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
// //         graph g = buildGraph(numCourses, prerequisites);
// //         vector<int> order;
// //         vector<bool> todo(numCourses, false), done(numCourses, false);
// //         for (int i = 0; i < numCourses; i++) {
// //             if (!done[i] && !acyclic(g, todo, done, i, order)) {
// //                 return {};
// //             }
// //         }
// //         reverse(order.begin(), order.end());
// //         return order;
// //     }
// // private:
// //     typedef vector<vector<int>> graph;
    
// //     graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
// //         graph g(numCourses);
// //         for (auto p : prerequisites) {
// //             g[p.second].push_back(p.first);
// //         }
// //         return g;
// //     }
    
// //     bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
// //         if (todo[node]) {
// //             return false;
// //         }
// //         if (done[node]) {
// //             return true;
// //         }
// //         todo[node] = done[node] = true;
// //         for (int neigh : g[node]) {
// //             if (!acyclic(g, todo, done, neigh, order)) {
// //                 return false;
// //             }
// //         }
// //         order.push_back(node);
// //         todo[node] = false;
// //         return true;
// //     }
// // };