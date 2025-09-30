#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen = 0;
        int currlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currlen++;
            }else{
                // Update the maximum length if the current length is greater
                maxlen = max(maxlen, currlen);
                //Reset the current length for consecutive zeros
                currlen = 0;
            }
        }
        //Update the maximum length after the loop (in case the sequence ends with ones)
        maxlen = max(maxlen, currlen);
        return maxlen;
    }
};
