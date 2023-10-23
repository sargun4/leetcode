#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;// {remainder,index}
        int sum=0;
        map[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int remainder=sum%k;
            //if 
            if(map.find(remainder)!=map.end()){
                if((i-map[remainder])>=2){
                    return true;
                }
            }else{
                map[remainder]=i;
            }
        }
        return false;
    }
};