class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n=grid.size();
        // int 
        for(int i=0;i<n;i++){
            sort(grid[i].rbegin(),grid[i].rend());//sort desc to get max in front
        }
        priority_queue<int,vector<int>,greater<>> pq;//minheap
        for(int i=0;i<n;i++){
            for(int j=0;j<limits[i];j++){
                pq.push({grid[i][j]});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        long long ans=0;
        while(!pq.empty()){
            long long num=pq.top(); pq.pop();
            ans+=num;
        }
        return ans;
    }
};