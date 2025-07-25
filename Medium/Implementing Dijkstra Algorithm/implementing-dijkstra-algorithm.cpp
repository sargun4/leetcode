#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex s.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s){
        //min heap= {dis,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(v);
        for(int i=0;i<v;i++){
            dist[i]=1e9; //initialise with +inf
        }
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int edgeWt=it[1];
                int adjnode=it[0];
                //relaxation
                if(dis+edgeWt<dist[adjnode]){
                    dist[adjnode]=dis+edgeWt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};


int main(){
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
