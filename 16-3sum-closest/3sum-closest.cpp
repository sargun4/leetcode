class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int res=nums[0]+nums[1]+nums[n-1];
        sort(nums.begin(), nums.end());
        //2ptr
        for(int i=0;i<n-2;i++){
            int aptr=i+1;
            int bptr=n-1;
            while(aptr<bptr){
                int currsum=nums[i]+nums[aptr]+nums[bptr];
                if(currsum>target){
                    bptr-=1;
                }else{
                    aptr+=1;
                }
                if(abs(currsum-target)<abs(res-target)){
                    res=currsum;
                }
            }
        }
        return res;
    }
};