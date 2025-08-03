class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=-1, q=-1;
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]){//no 2 elmnts can be equal
                return false;
            }
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){//maxima
                if(p==-1){
                    p=i;
                }else{
                    return false;
                }
            }if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){//minima
                if(q==-1){
                    q=i;
                }else{
                    return false;
                }
            }
        }
        //both p and q set(inc,dec,inc) n maxima must come first;
        return p!=-1 && q!=-1 && p<q;
    }
};