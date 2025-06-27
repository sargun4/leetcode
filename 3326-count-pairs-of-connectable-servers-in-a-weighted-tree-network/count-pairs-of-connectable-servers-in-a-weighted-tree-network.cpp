class Solution {
public:
    //bfs from one child subtree (child of node)
    //-ensures we do not revisit the parent
    //-counts nodes whose dist from node is divisible by signalSpeed
    int bfs(vector<pair<int,int>> graph[],int node,int parent,int wt,int signalSpeed){
        queue<pair<int,pair<int,int>>> q;//{node,{parent,dist}}
        q.push({node,{parent,wt}});
        int ans=0;
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            int node=curr.first;
            int parent=curr.second.first;
            int dist=curr.second.second;//wt=dist
            //if curr node c is at valid dist ie if (dist from parent)%signalSpeed, then ans+=1;
            if(dist%signalSpeed==0) ans++;
            for(auto it:graph[node]){
                int neigh=it.first;
                int wt=it.second;
                if(neigh!=parent){
                    q.push({neigh,{node,dist+wt}});
                }
            }
        }
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1;
        //weighted undir graph
        vector<pair<int,int>> graph[n];
        for(auto &e:edges){
            int u=e[0]; int v=e[1]; int wt=e[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){//each node as root
            int total=0;
            vector<int> arr;
            //find no of nodes w valid dist frm curr node(i)-act as parent
            for(auto it:graph[i]){//i-parent
                int child=it.first;
                int wt=it.second;
                int res=bfs(graph,child,i,wt,signalSpeed);
                // if no of nodes hving valid dist frm node i>0, add to arr
                if(res>0){
                    arr.push_back(res);
                    total+=res;
                }
            }
        //count unordered pairs (a, b) such that a < b frm diff subtrees rooted at i
            if(arr.size()>1){
                int res=0;
                for(auto i:arr){
                    res+=i*(total-i);//each x pairs with all others
                }
            //the pair (a,b) is counted twice cuz of given condition a < b in question
                ans[i]=res/2;
            }
        }
        return ans;
    }
};