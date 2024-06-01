class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]+=1;
            if(m[nums[i]]>1){
                return nums[i];
            }
        }
        return n;
    }
};