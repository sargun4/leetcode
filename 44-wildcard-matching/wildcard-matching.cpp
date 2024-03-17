
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(s, p, n, m, dp);
    }

    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) // Both strings are empty, match
            return true;
        if (j == 0) // Pattern is empty, but string still has characters
            return false;
        if (i == 0) { // String is empty, but pattern still has characters
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') // If remaining pattern characters are not '*', no match
                    return false;
            }
            return true; // If only '*'s are remaining, match
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = f(s, p, i - 1, j - 1, dp);

        if (p[j - 1] == '*')
            return dp[i][j] = f(s, p, i - 1, j, dp) || f(s, p, i, j - 1, dp);

        return dp[i][j] = false;
    }
};