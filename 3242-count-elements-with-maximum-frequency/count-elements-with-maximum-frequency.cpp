// https://leetcode.com/problems/count-elements-with-maximum-frequency/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        // Frequency Calculation
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        //  Find Maximum Frequency
        int maxi = 0;
        for (auto x : freq) {
            if (x.second > maxi) {
                maxi = x.second;
            }
        }

        // Calculate Total Frequency with Maximum Frequency
        int ans = 0;
        for (auto x : freq) {
            if (x.second == maxi) {
                ans += maxi;
            }
        }
        return ans;
    }
};
// Iterate through the elements of the array nums.
// Use an unordered map freq to keep track of the frequency of each element.
// Find Maximum Frequency:
// Iterate through the unordered map (freq) and find the maximum frequency (maxi).
// Calculate Total Frequency with Maximum Frequency:
// Iterate through the unordered map (freq) again.
// For each element, if its frequency is equal to the maximum frequency (maxi), add this frequency to the answer (ans).

