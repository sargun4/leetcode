#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int bit=0;bit<=20;bit++){
            //check for this bit
            int xorval=0;
            for(auto el:nums){
                int bitval=(1<<bit)&el;
                xorval=xorval^bitval;
            }
            int kbitval=(1<<bit)&k;
            if(xorval!=kbitval) ans++;;
        }
        return ans;
    }
};