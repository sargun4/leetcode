#include <vector>

class Solution {
public:
    int numTeams(std::vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        
        for (int i = 0; i < n; i++) {
            int left = 0, right = 0;
            
            // Count how many elements to the left are smaller than rating[i]
            for (int j = 0; j < i; j++) {
                if (rating[i] < rating[j]) {
                    left++;
                }
            }
            // Count how many elements to the right are larger than rating[i]
            for (int j = i + 1; j < n; j++) {
                if (rating[i] > rating[j]) {
                    right++;
                }
            }
            ans += left * right;
            
            // Count how many elements to the left are larger than rating[i]
            left = 0;
            for (int j = 0; j < i; j++) {
                if (rating[i] > rating[j]) {
                    left++;
                }
            }
            // Count how many elements to the right are smaller than rating[i]
            right = 0;
            for (int j = i + 1; j < n; j++) {
                if (rating[i] < rating[j]) {
                    right++;
                }
            }
            ans += left * right;
        }
        
        return ans;
    }
};