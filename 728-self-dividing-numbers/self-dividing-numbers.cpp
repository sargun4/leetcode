class Solution {
public:
    bool isSelfDividing(int num) {
        string s = to_string(num);
        for (char ch : s) {
            int digit = ch - '0'; // Convert character to digit
            if (digit == 0 || num % digit != 0) {
                return false; // Not self-dividing
            }
        }
        return true; // All digits divide the number
    } 
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int num = left; num <= right; num++) {
            if (isSelfDividing(num)) {
                result.push_back(num);
            }
        }
        return result;
    }
};