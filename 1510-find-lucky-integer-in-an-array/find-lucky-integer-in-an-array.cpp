class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        int maxlucky=-1;
        for(auto &it:freq){
            int val=it.first;
            int ctr=it.second;
            if(ctr==val && val>maxlucky){
                maxlucky=val;
            }
        }
        return maxlucky;
    }
};