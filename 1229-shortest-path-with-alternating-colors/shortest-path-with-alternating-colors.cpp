class Solution {
public:
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // constructing adjacency matrix
		vector<vector<pair<int,int>>> adj(n); //{node_idx,edge_color}
        for(auto e:red_edges)
            adj[e[0]].emplace_back(e[1],0);//red edges=0 
        for(auto e: blue_edges)
            adj[e[0]].emplace_back(e[1],1);//blue edges=1
        vector<int> dist(n,-1); 
        
        queue<vector<int>> q;//{idx,dist,colour}
        q.emplace(vector<int>{0,0,-1});
        
        while(!q.empty()) {
            auto curr = q.front();
            int idx=curr[0];
            int mindist=curr[1];
            int color=curr[2];
            q.pop();
            dist[idx]= (dist[idx]!=-1) ? dist[idx] : mindist;
            
            for(auto &adj : adj[idx]) {
				//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
				//for the first time.
                if(color!=adj.second && adj.first!=-1) {
                    q.emplace(vector<int>{adj.first, mindist + 1, adj.second});
					//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
                    adj.first = -1;
                }
            }
        }
        return dist;
    }
};