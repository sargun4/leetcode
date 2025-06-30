#include <algorithm>
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;//max subseq len 
        unordered_map<int,int> map;
        for(int &i:nums){
            map[i]++;
        }
        for(int &i:nums){
            int minval=i;
            int maxval=i+1;
            
            if(map.count(maxval)){
                ans=max(ans, map[minval]+map[maxval] );
            }
        }
        return ans;
    }
};