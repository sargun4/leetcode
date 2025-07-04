class Solution {
public:
    void backtrack(vector<string>& ans, string s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        
        if (open < n) 
            backtrack(ans, s + '(', open + 1, close, n);
        
        if (close < open) 
            backtrack(ans, s + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};


