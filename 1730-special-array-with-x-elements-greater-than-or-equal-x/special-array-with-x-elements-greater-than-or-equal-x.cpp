class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        int ctr=0;
        vector<int> freq(n+1,0);
        for(auto elmnt:nums){
            freq[min(n,elmnt)]++;
        }
        for(int i=n;i>=1;i--){
            ctr+=freq[i];
            if(ctr==i) return i;
        }
        return -1;
    }
};