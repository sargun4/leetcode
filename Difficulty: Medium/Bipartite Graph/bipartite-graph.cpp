class Solution {
public:
    bool bfs(int curr,vector<int>&color,int currcolor,vector<vector<int>> &adj){
        queue<int> q; 
        q.push(curr);
        color[curr]=currcolor;
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(int neigh:adj[node]){
                if(color[node]==color[neigh]){//adj node same color as node-NOT bipartite
                    return false;
                }else if(color[neigh]==-1){//not yet vis,mark it w alt color
                    color[neigh]=!color[node];
                    q.push(neigh);
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> color(V,-1);//ALL Uncolored initially
        //red=1; green=0; 
        for(int i=0;i<V;i++){
            if(color[i]==-1){//not yet vis
                if(bfs(i,color,1,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};




// class Solution {
// public:
//     bool bfs(vector<int>adj[],int curr,vector<int> &color,int currcolor){
//         queue<int> q;
//         q.push(curr);
//         color[curr]=currcolor;
//         while(!q.empty()){
//             int u=q.front();
//             q.pop();
//             for(int &v:adj[u]){
//                 if(color[v]==color[u])
//                     return false;
//                 else if(color[v]==-1){//not vis yet
//                     color[v]=1-color[u];
//                     q.push(v);
//                 }
//             }
//         }
//         return true;
//     } 
// 	bool isBipartite(int V, vector<int>adj[]){ 
// 	     vector<int> color(V, -1); //ALL UNCOlored initially
//         //red=1; green=0; 
//         for(int i=0;i<V;i++){
//             if(color[i]==-1){
//                 if(bfs(adj,i,color,1)==false){
//                     return false;
//                 }
//             }
//         } 
// 	}   
// };

