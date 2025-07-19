using p=pair<int,int>;
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
        map<p,int> used;
        int ans=0;
        priority_queue<p,vector<p>,greater<p>> pq;//{dist,node}
        pq.push({0,0});
        while(!pq.empty()){
            p curr=pq.top(); pq.pop();
            int d=curr.first; int node=curr.second;
            if(d>dist[node]){
                continue;
            }
//each node only vis once-we hv reached a node in our og graph
            ans++;
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
        //now each edge{u,v,wt} can be used w a max of w new nodes-
        // max of used[{u,v}]nodes frm 1 side n used[{v,u}] nodes frm other side
        for(auto e:edges){
            int u=e[0],v=e[1],wt=e[2];
            ans+=min(wt,used[{u,v}]+used[{v,u}]);
        }
        return ans;
    }
};