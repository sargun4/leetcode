class Solution {
public:
    bool isPrime(int num){
        if(num<=1) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(auto &i:nums){
            freq[i]++;
        }
        for(auto &it:freq){
            int freq=it.second;
            if(isPrime(freq)) return true;
        }
        return false;
    }
};