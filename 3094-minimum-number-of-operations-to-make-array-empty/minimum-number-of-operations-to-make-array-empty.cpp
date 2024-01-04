#include <bits/stdc++.h>
using namespace std;
class Solution { //O(n)
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int &num:nums){
            map[num]++;
        }
        int res=0;
        for(auto &it:map){
            int freq=it.second;
            if(freq==1){
                return -1;
            }
            res+=ceil((double)freq/3);
        }
        return res;
    }
};