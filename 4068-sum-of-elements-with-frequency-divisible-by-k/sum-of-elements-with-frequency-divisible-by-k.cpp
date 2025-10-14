class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freqMap;
        for(int num:nums){
            freqMap[num]++;
        }
        int ans=0;
        for(auto &it:freqMap){
            int num=it.first;
            int freq=it.second;
            if(freq%k==0){
                ans+=num*freq;
            }
        }
        return ans;
    }
};