class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefsum=0;
        int ans=0;
        unordered_map<int,int> prevoccCtr;
        prevoccCtr[0]=1;
        for(int i=0;i<n;i++){
            prefsum=(prefsum+nums[i]%k+k)%k;
            ans+=prevoccCtr[prefsum];
            prevoccCtr[prefsum]++;
        }
        return ans;
    }
};