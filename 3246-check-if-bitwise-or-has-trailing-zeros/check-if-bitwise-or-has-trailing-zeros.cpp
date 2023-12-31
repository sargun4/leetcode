#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count=0;
        for(auto num:nums){
            if(num%2==0) count++;
        }
        if(count>=2) return true;
        else return false;
    }
};