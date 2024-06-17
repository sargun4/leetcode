class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> lsum(n,0);
        vector<int> rsum(n,0);
        for(int i=0;i<n;i++){
            int k=0;
            while(k<i){
                lsum[i]+=nums[k];
                k++;
            }
            int l=n-1;
            while(l>i){
                rsum[i]+=nums[l];
                l--;
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=abs(lsum[i]-rsum[i]);
        }
        return ans;
    }
};