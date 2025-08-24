class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zeroCtr=0;//no of 0s in window
        int longestWindow=0;// longest window having at most one 0 we have seen so far
        int start=0;//left end of window
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCtr++;
            }
            //shrink the window till zeroCtr<=1
            while(zeroCtr>1){
                if(nums[start]==0){
                    zeroCtr--;
                }
                start++;//shrink window frm left by 1 unit
            }
            longestWindow=max(longestWindow,i-start);
        }
        return longestWindow;
    }
};