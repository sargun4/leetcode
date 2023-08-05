//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


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
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        disjointset ds(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1){
                    ds.unionbySize(i,j);
                }
            }
        }
        int ctr=0;
        for(int i=0;i<v;i++){
            if(ds.findUltimateParent(i)==i){
                ctr++;
            }
        }
        return ctr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends