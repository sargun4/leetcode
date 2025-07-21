class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map; //{x:freq}
        int ctr=0;
        for(int x:nums){
            int rem=k-x;
            if(map[rem]>0){
                ctr++;
                map[rem]--;
            }else{
                map[x]++;
            }
        }
        return ctr;
    }
};