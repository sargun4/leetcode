//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

  
#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    bool dfs(vector<int>adj[],int curr,vector<int>&color,int currcolor){
        color[curr] = currcolor;
        for(int &v:adj[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            if(color[v]==-1){//unvisited
                int vcolor=1-currcolor;
                if(dfs(adj,v,color,vcolor)==false)
                    return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1); //no nodes colored intiially
        for(int i=0;i<V;i++){
            if(color[i]==-1){//unviisted
                if(dfs(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends