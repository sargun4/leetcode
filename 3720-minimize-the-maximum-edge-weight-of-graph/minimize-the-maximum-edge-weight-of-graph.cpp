// - Instead of checking reachability from each node to 0, we reverse all edges.Then, we only need to check if all nodes are reachable from node 0 using BFS/DFS.
// - We use binary search on the answer (edge weight):
// - For a given threshold mid, we keep only edges with weight <= mid and check if all nodes are reachable from 0.
//   - If yes, we try smaller mid values.
//   - If no, we increase mid.

//1. Reverse the Graph
// - For every directed edge (u → v, wt), store (v → u, wt) in adj.  
//   This allows us to start a BFS from node 0 and verify reachability.
//2. BFS Check
// - For a given mid, we traverse the graph from node 0 using only edges where weight <= mid.  
// - If after BFS all nodes are visited, mid is valid
//3. Binary Search
// - Let maxwt = max(edge weights) be the upper bound.
// - Binary search mid in range [0, maxwt].
// - The smallest valid mid is our answer.
using p=pair<int,int>;
class Solution {
public:
    //bfs
    bool canAllReachZero(int n,unordered_map<int,vector<p>> &adj,int mid){
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);//start frm 0
        vis[0]=true;
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(auto &p:adj[node]){
                int neigh=p.first;
                int wt=p.second;//edge wt
                if(wt<=mid &&!vis[neigh]){//edgewt<=mid & neigh not yet vis-so we can remove this edge to get a better/smaller val
                    vis[neigh]=true;
                    q.push(neigh);
                }
            }
        }
        for(int i=0;i<n;i++){//check all nodes
            if(vis[i]==false){//this ith node wasnt vis-so unreachable from 0-in rev, 0 wud be unreachble frm that ith node- so condn false
                return false;//we coudnt visit all nodes
            }
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int maxwt=0;
        unordered_map<int,vector<p>> adj;
        // S-O(V+E)
        //form the adjList w rev edges- to get all nodes reachable frm 0 for bfs/dfs, instead of hving to call bfs/dfs frm each node to see whether 0 is reachable frm that node;
        for(auto &e:edges){//directed graph, rev
            int u=e[0],v=e[1],wt=e[2];
            adj[v].push_back({u,wt}); //v to u rev edge
            maxwt=max(maxwt,wt);
        }
        int ans=INT_MAX;
        int l=0; int r=maxwt; 
        //bin search on ans(wt)
        while(l<=r){//T-O(log(maxwt) *(v+e))
            int mid=l+(r-l)/2;
            if(canAllReachZero(n,adj,mid)==true){//bfs
                ans=mid;
                r=mid-1;//try smaller max wt
            }else{
                l=mid+1;
            }
        }
        return ans==INT_MAX ? -1:ans;//if ans not updated, means it is impossible for all conditions to be satisfied else return ans
    }
};