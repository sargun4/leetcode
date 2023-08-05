//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//KRUSKAL
class disjointset{
    vector<int> rank,parent,size;
public:
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        return findUltimateParent(parent[node]);
    }
    void unionbyRank(int u,int v){
        int ultParent_u=findUltimateParent(u);
        int ultParent_v=findUltimateParent(v);
        if(ultParent_u==ultParent_v){
            return;
        }
        if(rank[ultParent_u]<rank[ultParent_v]){
            parent[ultParent_u]=ultParent_v;
        }
        else if(rank[ultParent_u]>rank[ultParent_v]){
            parent[ultParent_v]=ultParent_u;
        }
        else{
            parent[ultParent_v]=ultParent_u;
            rank[ultParent_u]++;
        }
    }

    void unionbySize(int u,int v){
        int ultParent_u=findUltimateParent(u);
        int ultParent_v=findUltimateParent(v);
        if(ultParent_u==ultParent_v){
            return;
        }
        if(size[ultParent_u]<size[ultParent_v]){
            parent[ultParent_u]=ultParent_v;
            size[ultParent_v]+=size[ultParent_u];
        }else{
            parent[ultParent_v]=ultParent_u;
            size[ultParent_u]+=size[ultParent_v];
        }
    }   
};

class Solution{
	public:
    int spanningTree(int v, vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjnode}});

            }
        }
        disjointset ds(v);
        sort(edges.begin(),edges.end());
        int mstWt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
                mstWt+=wt;
                ds.unionbyRank(u,v);
            }
        }
        return mstWt;
    }
};

//PRIMS
// // T-O(ElogE),S-O(E)
// class Solution{
// 	public:
// 	//Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int v, vector<vector<int>> adj[]){
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<int> vis(v,0);
//         //{wt,node}
//         pq.push({0,0});
//         int sum=0;
//         while(!pq.empty()){
//             auto it=pq.top();
//             pq.pop();
//             int wt=it.first;
//             int node=it.second;

//             if(vis[node]==1) continue;
//             //add it to mst
//             vis[node]=1;
//             sum+=wt;
//             for(auto it:adj[node]){
//                 int adjnode=it[0];
//                 int edgeWt=it[1];
//                 if(!vis[adjnode]){
//                     pq.push({edgeWt,adjnode});
//                 }
//             }
//         }
//         return sum;
//     }
// };



//{ Driver Code Starts.


int main()
{
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends