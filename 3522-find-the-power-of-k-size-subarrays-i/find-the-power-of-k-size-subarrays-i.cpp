class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,-1); //no of subarrs that can b formed=n-k+1
        int ctr=1;//count of consec elmnts
        //preprocess 1st window
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]+1){
                ctr++;
            }else{
                ctr=1;
            }
        }
        if(ctr==k){
            ans[0]=nums[k-1];
        }
        int i=1;
        int j=k;
        //slidn window
        while(j<n){
            if(nums[j]==nums[j-1]+1){//consec
                ctr++;
            }else{
                ctr=1;
            }
            if(ctr>=k){//curr window of len k is consec
                ans[i]=nums[j];
            }
            i++; 
            j++;
        }
        return ans;
    }
};