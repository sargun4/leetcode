// 1. The graph has both original nodes and new subdivided nodes on each edge.
// 2. We treat the graph as a weighted graph where each edge weight = ctr + 1 (to represent the cost to cross that entire edge).
// 3. We run Dijkstra's algorithm to find the shortest distance from 0 to all original nodes.
// 4. While processing edges, we count:
//    - Original nodes visited within maxMoves.
//    - Partial subdivisions reachable from both sides:
//      new_nodes_on_edge = min(w, used_from_u + used_from_v)
using p=pair<int,int>;//{dist, node}
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<p>> adj(n);
        for(auto e:edges){
            int u=e[0], v=e[1], wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        map<int,int> dist;
        dist[0]=0;
        for(int i=1;i<n;i++){
            dist[i]=maxMoves+1;
        }
        //map to store how many subdivided nodes r used on edge {u, v}
        map<p,int> used;
        int ans=0;
        //minheap for dijkstra
        priority_queue<p,vector<p>,greater<p>> pq;//{dist,node}
        pq.push({0,0});
        while(!pq.empty()){
            p curr=pq.top(); pq.pop();
            int d=curr.first; int node=curr.second;
            if(d>dist[node]){
                continue;
            }
//each node only vis once-we hv reached a node in our og graph
            ans++;//og node
            for(auto pair:adj[node]){
                //maxMoves-d = how further we can walk frm this node;
                //wt=no of new nodes that r added on this edge 
                //v=max utilisation of this edge
                int neigh=pair.first;
                int wt=pair.second;
                used[{node,neigh}]=min(wt,maxMoves-d);
                //d2=total dist to reacg neigh in og graph
                int d2=d+wt+1;
                if(d2<min(dist[neigh],maxMoves+1)){
                    pq.push({d2,neigh});
                    dist[neigh]=d2;
                }
            }
        }
        //count subdivided nodes
        //now each edge{u,v,wt} can be used w a max of w new nodes-
        // max of used[{u,v}]nodes frm 1 side n used[{v,u}] nodes frm other side
        for(auto e:edges){
            int u=e[0],v=e[1],wt=e[2];
            ans+=min(wt,used[{u,v}]+used[{v,u}]);
        }
        return ans;
    }
};