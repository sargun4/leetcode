//using kahn's toposort
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto &e:prerequisites){//directed unweighted graph
            int u=e[0];int v=e[1];
            adj[u].push_back(v);//u -> v
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //prereqMap to track prereqs
        unordered_map<int,unordered_set<int>> prereqMap;//{course:{prereqs of it}}
        //O((V+E)*V) since we r visiting nodes' prereq also additionally  
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &neigh:adj[node]){
                prereqMap[neigh].insert(node);//cuz node is prepreq of neigh since there's directd edge frm node->neigh
                //add prepreqs of node as well, by transitivity, theyre prereq of neigh as well
                for(auto &prereq:prereqMap[node]){
                    prereqMap[neigh].insert(prereq);
                }
                //reduce indegree by 1 and push if zero
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        int len=queries.size();
        vector<bool> res(len,false);
        for(int i=0;i<len;i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            //if the dest node has prereq src, then it is reachabel
            bool reachable=prereqMap[dest].contains(src);
            res[i]=reachable;
        }
        return res;
    }
};
// class Solution {
// public:
//     bool dfs(unordered_map<int,vector<int>>&adj,int src,int dest,vector<bool> &vis){
//         vis[src]=true;
//         if(src==dest) return true;//we hv reached dest
//         bool isReachable=false;
//         for(auto&neigh:adj[src]){
//             if(!vis[neigh]){
//                 isReachable=isReachable|| dfs(adj,neigh,dest,vis);
//             }
//         }
//         return isReachable;
//     }
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         unordered_map<int,vector<int>> adj;
//         for(auto &e:prerequisites){//directed unweighted graph
//             int u=e[0];int v=e[1];
//             adj[u].push_back(v);
//         }
//         int q=queries.size();
//         vector<bool> res(q);
//         for(int i=0;i<q;i++){
//             int u=queries[i][0];//src
//             int v=queries[i][1];//dest
//             vector<bool> vis(numCourses,false);
//             res[i]=dfs(adj,u,v,vis);
//         }
//         return res;
//     }
// };