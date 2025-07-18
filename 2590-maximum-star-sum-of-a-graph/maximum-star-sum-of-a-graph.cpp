class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        //edge wt bw 2 nodes = sum of their vals
        int n=vals.size();//no of nodes in grpah
        vector<vector<int>> adj(n);//{u,v}
        for (auto &e:edges){
            int u =e[0],v=e[1];
            adj[u].push_back(vals[v]);//store value of neighbor
            adj[v].push_back(vals[u]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            //sort neighs in descending order
            auto &neighs = adj[i];
            sort(neighs.begin(), neighs.end(), greater<int>());
            long long sum = vals[i];//include curr node value
            for (int j = 0; j < k && j < (int)neighs.size(); j++) {
                if (neighs[j] > 0) sum += neighs[j];//addin only positive vals
                else break; //no point adding negatives
            }   
            ans = max(ans, (int)sum);
        }      
        return ans;
    }
};