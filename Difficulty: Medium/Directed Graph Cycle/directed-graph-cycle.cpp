// if topo sort doesnt exist = cycle exists
// since topo sort exists only for DAG;
//KAHN's algo
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for(auto it:edges){//directd graph, u->v
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indeg(V,0);
        vector<int>ans; //store topo order
        //get indeg of each node and store in indeg
        for(int i=0;i<V;i++){
            for(auto &v:adj[i]){
                indeg[v]++;
            }
        }
        //now push nodes w indeg=0 in q
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int ctr=0;
        while(!q.empty()){
            int node=q.front(); q.pop();
            ctr++;
            ans.push_back(node);
            for(int neigh:adj[node]){
                indeg[neigh]--;
                if(indeg[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        //if ctr is not equal to V then there is a cycle present in the graph
        if(ctr == V){
            return false;
        }
        return true;
    }
};

