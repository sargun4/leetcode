class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());//asc order
        int n=nums.size();
        int ans=1;//min 1 subseq reqd.
        int min=nums[0];//1st elmnt initally the min cuz asc ordered
        for(int i=1;i<n;i++){
            if(nums[i]-min>k){//if diff of each subseq elmnt with min goes more than k
                ans++;//new subseq added
                min=nums[i];//min updated to start new subseq
            }
        }
        return ans;
    }
};