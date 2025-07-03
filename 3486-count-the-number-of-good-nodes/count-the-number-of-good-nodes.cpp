class Solution {
public:
    vector<vector<int>> adj;//undir graph
    int ans=0;//count of good nodes-hv same subtree size for each of its child

    int dfs(int node,int parent){//rec to compute subtree sizes
        int totalNodes=0;
        bool isgood=true;
        int subtreeSize = -1;//size of first child subtree 
        for(auto &neigh:adj[node]){
            if(neigh==parent) continue;//avoidin going bk to paernt
            int currsize=dfs(neigh,node);//size of child's subtree
            if(subtreeSize==-1){
                subtreeSize=currsize;//store size of 1st child subtree
            }else if(currsize!=subtreeSize){
                isgood=false;
            }
            totalNodes+=currsize;
        }
        if (isgood) ans++;//if curr node is good
        return totalNodes+1;//currnode too added
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;//no of nodes
        adj.resize(n);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0,-1);//dfs frm node 0-root with no parent
        return ans;
    }
};