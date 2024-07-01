class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ctr = 0; 
        for (int num : arr) { // Iterate through each element in the array
            if (num % 2 != 0) { // Check if the current element is odd
                ctr++; // Increment the ctr if it's odd
                if (ctr == 3) { // If we have found three consecutive odds, return true
                    return true;
                }
            } else { // If the element is even, reset the ctr to 0
                ctr = 0;
            }
        }
        return false; // If we finish the loop without finding three consecutive odds, return false
        
    }
};