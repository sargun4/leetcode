#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> last_idx;//{num:lastidx}
        for(int i=0;i<n;i++){
            last_idx[nums[i]]=i;
        }
        int i=0;
        int j=0;
        j=max(j,last_idx[nums[0]]);
        int res=1;
        while(i<n){
            if(i>j){ //we got a partition
                res=(res*2)%mod;
            }
            j=max(j,last_idx[nums[i]]);
            i++;
        }
        return res;
    }
};