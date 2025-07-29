class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        // setBitIdx[j]=i, means that jth bit can be set via elmnt at idx i in nums
        vector<int> setBitIdx(32,-1);
        for(int i=n-1;i>=0;i--){
            int endidx=i;
            //nums[i]=binary repr
            for(int j=0;j<32;j++){
                if(!(nums[i] & (1<<j))){//if jth bit not set
                    if(setBitIdx[j]!=-1){
                        endidx=max(endidx,setBitIdx[j]);
                    }
                }else{
                    setBitIdx[j]=i;
                }
            }
            res[i]=endidx-i+1;
        }
        return res;
    }
};