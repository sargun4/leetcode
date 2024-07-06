// class Solution {
// public:
//     int passThePillow(int n, int time) {
//         int chunks = time / (n - 1);
//         return chunks % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
//     }
// };
class Solution {
    public:
    int passThePillow(int n, int time) {
        int completed = time / (n-1);
        int rem = time % (n-1);
        int ans = 0;
        if (completed % 2 != 0) {
            ans = n - rem;
        } else {
            ans = rem + 1;
        }
        return ans;
    }
};