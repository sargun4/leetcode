class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> adj(n);//dag
        for(auto e:edges){
            int u=e[0]; int v=e[1]; int wt=e[2];
            adj[u].push_back({v,wt});
        }
        vector<vector<set<int>>> dp(n,vector<set<int>>(k+1));
        //base case
        for(int u=0;u<n;u++){
            dp[u][0].insert(0);
        }
        for(int e=0;e<k;e++){
            for(int u=0;u<n;u++){
                for(auto&[v,wt]:adj[u]){
                    for(auto&w:dp[u][e]){
                        int new_wt=w+wt;
                        if(new_wt<t){
                            dp[v][e+1].insert(new_wt);
                        }
                    }
                }
            }
        }
        //find max wt across all nodes that used exactly k edges
        int ans = -1;
        for(int u = 0; u < n; u++){
            if(!dp[u][k].empty()) 
                ans = max(ans, *prev(dp[u][k].end()));
        }
        return ans;
    }
};