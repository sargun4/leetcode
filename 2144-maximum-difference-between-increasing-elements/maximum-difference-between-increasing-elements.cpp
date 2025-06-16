class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int minelmnt=nums[0];
        int maxdiff=-1;
        for(int j=1;j<n;j++){
            if(nums[j]>minelmnt){
                maxdiff=max(maxdiff,nums[j]-minelmnt);
            }else{
                minelmnt=nums[j];
            }
        }
        return maxdiff;
    }
};