//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
 #include<bits/stdc++.h>
using namespace std;
 
class Solution{
    public:
      vector<int>maximumDistance(vector<vector<int>> edges,int v,int e,int src){
        vector<vector<int>> adj[v];
        for(auto edge : edges)
            adj[edge[0]].push_back( {edge[1],  -edge[2]} );
        vector<int> dist_arr(v, 1e9);
        dist_arr[src] = 0;
        queue<int> q;
        q.push(src);
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
        for(int i=0;i<dist_arr.size();i++){
            if(dist_arr[i]==1e9) dist_arr[i]=INT_MIN;
            else dist_arr[i]=-dist_arr[i];
        }
        return dist_arr ;
      }
}; 

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends