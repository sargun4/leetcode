//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <bits/stdc++.h>
using namespace std;
// You are given an Undirected Graph having unit weight, Find the
//  shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
class Solution {
public:
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // Create a graph from the input adjacency list representation 
        vector<int> adj[N];
        for(auto it:edges){//undirected graph
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> result(N,-1) , visited(N) ; 
        queue<pair<int,int>> q ; 
        q.push({src,0}) ; 
        result[src]=0 ; 
        visited[src]=1 ; 
        while(!q.empty()){
            int i = q.front().first ;
            int dist = q.front().second ;
            q.pop() ; 
            for(int j=0 ; j<adj[i].size() ; j++){
                if(!visited[adj[i][j]]){
                    visited[adj[i][j]]=1 ; 
                    q.push({adj[i][j],dist+1}) ; 
                    result[adj[i][j]] = dist+1 ; 
                }
            }
        }
        return result ; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends