//need max path sum with only R or D movts
class Solution {
public:
    int solve(int i, int j, const vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        //base case: bottom right cell (princess room)
        if (i==m-1 && j==n-1){
            return max(1,1-dungeon[i][j]);//knight needs atleast 1 health at final cell to survive
        }
        //if out of bounds
        if(i>=m||j>=n) {
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = solve(i, j + 1, dungeon, dp);
        int down = solve(i + 1, j, dungeon, dp);
        //knight needs at least 1 health point to survive
        int min_health=min(right, down) - dungeon[i][j];
        dp[i][j]=max(1,min_health);
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        //memo
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0,0,dungeon,dp);
    }
};