class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> map;
        int res=0;
        int currsum=0;
        map[0]=1; //0 currsum exists once initally
        for(int &num : nums){
            currsum+=num;
            int remsum=currsum-goal;
            if(map.find(remsum)!=map.end()){ //if remsum already exist in map
                res+=map[remsum];
            }
            map[currsum]++;
        }
        return res;
    }
};