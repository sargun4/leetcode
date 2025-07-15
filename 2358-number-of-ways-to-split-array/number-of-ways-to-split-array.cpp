using ll=long long;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        ll sum=0;
        for(int &num:nums){
            sum+=num;
        }
        ll lsum=0;
        ll rsum=0;
        int split=0;
        for(int i=0;i<n-1;i++){
            lsum+=nums[i];
            rsum=sum-lsum;
            if(lsum>=rsum){
                split++;
            }
        }
        return split;
    }
};