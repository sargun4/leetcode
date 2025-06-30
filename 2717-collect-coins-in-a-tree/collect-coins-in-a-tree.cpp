class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;//q for leaf nodes which can be removed
        //del leaves w no coins
        for(int i=0;i<n;i++){
            if(degree[i]==1 && coins[i]==0){//leaf node w no coin
            q.push(i);
            }
        }
        vector<bool> removed(n,false);//those nodes whichll be removed

        while(!q.empty()){
            int node=q.front();
            q.pop();
            removed[node]=true;
            //reduce degree of neighbors n check if they become new useless leaves
            for(int neigh:graph[node]){
                // if (removed[neighbor]) 
                // continue; //skip already removed nodes

                degree[neigh]--;
            //if neigh becomes a leaf & has no coin, remove it too
                if(degree[neigh]==1 && coins[neigh]==0){
                    q.push(neigh);
                }
            }
        }
    //snce coins within dist=2 can be collected from a node, we don't need to walk to leaf coins
        for(int step=0;step<2;step++){
            queue<int> q2;
            for(int i=0;i<n;i++){
                if(!removed[i] && degree[i]==1){//if leaf has coin
                    q2.push(i);
                }
            }

            // 2nd bfs
            while(!q2.empty()){
                int node=q2.front();
                q2.pop();
                removed[node]=true;
                for(int neigh:graph[node]){
                    if(removed[neigh]==false){
                        degree[neigh]--;
                    }
                }
            }
        }
        int rem_nodes=0;//remainig nodes
        for(int i=0;i<n;i++){
            if(!removed[i]) rem_nodes++;
        }
        return max(0,(rem_nodes-1)*2);
    }
};