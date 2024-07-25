class Solution {
public:
    string losingPlayer(int x, int y) {
        int moves=0;
        while(true){
            if(x>0 && y>=4){
                x--;
                y-=4;
                moves++;
            }
            else break;
        }
        if(moves%2==0) return "Bob";
        else return "Alice";
    }
};
// Time complexity : O(log(min(x,y)))
// The time complexity of this function is O(log(min(x, y))) because the while loop will iterate until either x becomes 0 or y becomes less than 4, which will happen in log(min(x, y)) steps.

// Space complexity : O(1)

