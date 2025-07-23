class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> deq;//stores idx in monotonic increasing order of cumulative sum
        vector<long long> cumulativeSum(n,0);//stores cumulative sum of nums
        int res=INT_MAX;//need to find min size subarr whose sum>=k
        int j=0;
        while(j<n){
            if(j==0){
                cumulativeSum[j]=nums[j];
            }else{
                cumulativeSum[j]=cumulativeSum[j-1]+nums[j];
            }
            if(cumulativeSum[j]>=k){
                res=min(res, j-0+1);
            }
            // Check if we can shrink the window from the front
            while(!deq.empty() && cumulativeSum[j]-cumulativeSum[deq.front()] >= k){
                res=min(res,j-deq.front());
                deq.pop_front();
            }
            // Maintain monotonicity of prefix values
             while(!deq.empty() && cumulativeSum[j]<=cumulativeSum[deq.back()]){
                deq.pop_back();
            }
            //push curr index
            deq.push_back(j);
            j++;
        }
        return res==INT_MAX ? -1:res ;
    }
};