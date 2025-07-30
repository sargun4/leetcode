class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m=nums.size();//no of rows
        int n=nums[0].size();//noof cols
        for(int i=0;i<m;i++){
            sort(nums[i].begin(), nums[i].end());
        }
        int sum=0;
        // For each column from left to right
        for(int j=0;j<n;j++){//goin over all cols
            priority_queue<int> pq;//maxheap
            for(int i=0;i<m;i++){
                pq.push(nums[i][j]);
            }
            sum+=pq.top();//top has max elmnt
        }
        return sum;
    }
};