//tab
class Solution {
    public int rob(int[] num) {
        int[][] dp = new int[num.length + 1][2];
        for (int i = 1; i <= num.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = num[i - 1] + dp[i - 1][0];
        }
        return Math.max(dp[num.length][0], dp[num.length][1]);
    }
}
// //memo
// class Solution {
//     public int rob(int[] num) {
//         int rob = 0; //max monney can get if rob current house
//         int notrob = 0; //max money can get if not rob current house
//         for(int i=0; i<num.length; i++) {
//             int currob = notrob + num[i]; //if rob current value, previous house must not be robbed
//             notrob = Math.max(notrob, rob); //if not rob ith house, take the max value of robbed (i-1)th house and not rob (i-1)th house
//             rob = currob;
//         }
//         return Math.max(rob, notrob);
//     }
// }
