class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<int> diff;
        int mincost=0;
        for(int i=0;i<n;i++){
            mincost+=costs[i][0];
            diff.push_back(costs[i][1]-costs[i][0]);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n/2;i++){
            mincost+=diff[i];
        }
        return mincost;
    }
};