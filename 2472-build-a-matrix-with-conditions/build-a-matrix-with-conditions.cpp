//usinf bfs-kahns topo
class Solution {
public:     
    vector<int> toposort(vector<vector<int>> &edges,int &n){
        //make adj list-graph repr
        unordered_map<int,vector<int>>adj;
        vector<int> indeg(n+1,0);
        for(vector<int>&edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        int ctr=0;
        vector<int> topo;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
                ctr++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(int &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                    ctr++;
                }
            }
        }
        if(ctr!=n){ //cycle exists
            return {};
        }
        return topo;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // rowConditions[i] = [abovei, belowi]
        // colConditions[i] = [lefti, righti]
        int n=rowConditions.size();
        int m=colConditions.size();

        vector<int> toporow=toposort(rowConditions,k);
        vector<int> topocol=toposort(colConditions,k);

        if(toporow.empty()||topocol.empty()){
            return {}; //found cycle. ans not possible
        }

        vector<vector<int>> mat(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(toporow[i]==topocol[j]){
                    mat[i][j]=toporow[i];
                }
            }
        }
        return mat;
    }
};
//using dfs-toposort
// class Solution {
// public:
//     void dfs(int u,vector<int>&vis,unordered_map<int,vector<int>>&adj,
//     stack<int>&st,bool &cycle){
//         vis[u]=1;
//         for(int &v:adj[u]){
//             if(vis[v]==0){
//                 dfs(v,vis,adj,st,cycle);
//             }else if(vis[v]==1){
//                 cycle=true;
//                 return;
//             }
//         }
//         vis[u]=2; //visited now
//         st.push(u);
//     }
//     vector<int> toposort(vector<vector<int>> &edges,int &n){
//         //make adj list-graph repr
//         unordered_map<int,vector<int>>adj;
//         for(vector<int>&edge:edges){
//             int u=edge[0];
//             int v=edge[1];
//             adj[u].push_back(v);
//         }
//         vector<int> vis(n+1,0);
//         // vis[i]=0 ; //not vis
//         // vis[i]=1 ; //dfs is ongonig frm ith node
//         stack<int> st;
//         vector<int> order;
//         bool cycle=false;
//         for(int i=1;i<=n;i++){
//             if(vis[i]==0){
//                 dfs(i,vis,adj,st,cycle);
//                 if(cycle==true){
//                     return{};
//                 }
//             }
//         }
//         while(!st.empty()){
//             order.push_back(st.top());
//             st.pop();
//         }
//         return order;
//     }
//     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
//         // rowConditions[i] = [abovei, belowi]
//         // colConditions[i] = [lefti, righti]
//         int n=rowConditions.size();
//         int m=colConditions.size();

//         vector<int> toporow=toposort(rowConditions,k);
//         vector<int> topocol=toposort(colConditions,k);

//         if(toporow.empty()||topocol.empty()){
//             return {}; //found cycle. ans not possible
//         }

//         vector<vector<int>> mat(k,vector<int>(k,0));
//         for(int i=0;i<k;i++){
//             for(int j=0;j<k;j++){
//                 if(toporow[i]==topocol[j]){
//                     mat[i][j]=toporow[i];
//                 }
//             }
//         }
//         return mat;
//     }
// };