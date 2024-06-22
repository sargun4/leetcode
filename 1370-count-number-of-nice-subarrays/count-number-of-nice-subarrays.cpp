class Solution {
public:
    int noOfsubarrslessthaneqtok(vector<int>& nums, int k){
        int i=0; int j=0;
        int n=nums.size();
        int ctr=0;//no of 1s in the range
        int ans=0;//numberOfSubarrays
        while(j<n){
            if(nums[j]%2!=0){
                ctr++;
            }
            while(i<=j && ctr>k){
                if(nums[i]%2!=0){
                    ctr--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return noOfsubarrslessthaneqtok(nums,k)-noOfsubarrslessthaneqtok(nums,k-1);

    }
};