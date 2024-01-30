class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }

private:
    void dfs(const vector<string>& arr, const string& path, int idx, int& result) {
        if (isUniqueChars(path)) {
            result = max(result, static_cast<int>(path.length()));
        }

        if (idx == arr.size() || !isUniqueChars(path)) {
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, result);
        }
    }
    bool isUniqueChars(const string& s) {
        unordered_set<char> set;
        for (char c : s) {
            if (set.count(c)) {
                return false;
            }
            set.insert(c);
        }
        return true;
    }
};
// Approach 2: DFS
// Intuition:
// The idea is to use Depth-First Search (DFS) to explore all possible combinations of strings in the array.
// At each step, we concatenate a string to the existing path and check for uniqueness.
// We keep track of the maximum length of valid subsequences during the DFS traversal.
// Approach:
// Initialize the result variable to 0.
// Define a DFS function that takes the array, current path, and current index as parameters.
// In the DFS function:
// a. Check if the current path has unique characters using a helper function isUniqueChars.
// b. If the path is unique, update the result with the maximum length.
// c. If the current index is equal to the array size or the path is not unique, return.
// d. Iterate through the array starting from the current index and make recursive calls to the DFS function.
// Call the DFS function with the initial parameters.
// Complexity Analysis:
// Time Complexity: Exponential, O(2^M), where M is the maximum length of a string in the array. The DFS explores all possible combinations.
// Space Complexity: O(M), where M is the maximum length of a string. The space is used for the recursive call stack.