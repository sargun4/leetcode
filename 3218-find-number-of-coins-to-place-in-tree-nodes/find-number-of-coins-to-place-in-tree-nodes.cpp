typedef long long ll;

class Solution {
public:
    int n;
    vector<vector<int>> graph;
    vector<int> cost;
    vector<ll> coins;

    // Merge two vectors and keep only top 3 largest and 2 smallest values
    vector<ll> mergeAndTrim(vector<ll>& a, vector<ll>& b) {
        vector<ll> all = a;
        all.insert(all.end(), b.begin(), b.end());
        sort(all.begin(), all.end());

        vector<ll> trimmed;

        // Keep 2 smallest values
        for (int i = 0; i < min(2, (int)all.size()); ++i)
            trimmed.push_back(all[i]);

        // Keep 3 largest values
        for (int i = max((int)all.size() - 3, 2); i < (int)all.size(); ++i)
            trimmed.push_back(all[i]);

        return trimmed;
    }

    vector<ll> dfs(int src, int parent) {
        vector<ll> vals = {(ll)cost[src]};

        for (int child : graph[src]) {
            if (child == parent) continue;
            vector<ll> sub = dfs(child, src);
            vals = mergeAndTrim(vals, sub);
        }

        // Calculate coin value
        int len = vals.size();
        if (len < 3) {
            coins[src] = 1;
        } else {
            // Check max product of any 3 from selected 5 values
            ll maxProd = 0;
            for (int i = 0; i < len; ++i) {
                for (int j = i + 1; j < len; ++j) {
                    for (int k = j + 1; k < len; ++k) {
                        ll prod = vals[i] * vals[j] * vals[k];
                        maxProd = max(maxProd, prod);
                    }
                }
            }
            coins[src] = maxProd > 0 ? maxProd : 0;
        }

        return vals;
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& costInput) {
        cost = costInput;
        n = cost.size();
        graph.assign(n, {});
        coins.assign(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return coins;
    }
};
