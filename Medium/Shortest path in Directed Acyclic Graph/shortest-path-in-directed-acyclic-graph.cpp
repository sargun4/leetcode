//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;  
class Solution {
public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<int>> adj[N];
        for(auto e : edges)
            adj[e[0]].push_back( {e[1], e[2]} );
        vector<int> dist_arr(N, INT_MAX);
        dist_arr[0] = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int node = q.front();   
            q.pop(); 
            for(auto neighbor : adj[node]){
                int neigh = neighbor[0] ;
                int dist = neighbor[1];
                if(dist_arr[node] + dist < dist_arr[neigh]){
                    dist_arr[neigh] = dist_arr[node] + dist ;
                    q.push(neigh);
                }
            }
        }
        for(auto &a : dist_arr)
            if(a==INT_MAX)
                a = -1;
        return dist_arr ;
    }
}; 

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends