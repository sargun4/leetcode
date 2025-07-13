class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); //adj list
        for(auto it:flights) {//directed edge
            adj[it[0]].push_back({it[1],it[2]}); //it[0]=src node, it[1]=dest node, it[2]=cost
        }
        vector<int> price(n,INT_MAX);//vector to store min price to reach each node from src
        price[src]=0; //price to reach src node from itself=0
    
        queue<pair<int,pair<int,int>>> q;//{no. of stops,{curr node,curr cost}}
        q.push({0,{src,0}});//start with the src node, 0 stops, and cost 0

        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int stops = p.first; // no of stops made to reach the curr node
            int node = p.second.first; // curr node
            int cost = p.second.second; // cost to reach the curr node
            //if no. of stops exceeds k, skip processing further
            if(stops > k) {
                continue;
            }
            for(auto it : adj[node]) {
                //if no. of stops is within the limit & new cost is less than the prev recorded cost
                int edgewt=it.second;
                int neigh=it.first;
                if((stops<=k) && (cost+edgewt)<price[neigh]) {
                    price[neigh]=cost+edgewt;//update cost to reach adj node
                    q.push({stops+1,{neigh,price[neigh]}});//push adj node into q with updated cost and stops
                }
            }
        }
        // if price to reach dest node is still INT_MAX, it means it's unreachable
        if(price[dst]==INT_MAX) return -1;
        return price[dst];//min price to reach the dest node
    }
};
