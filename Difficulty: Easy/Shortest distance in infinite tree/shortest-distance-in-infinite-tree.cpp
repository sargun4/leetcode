class Solution {
public:
int distance(int X, int Y) {
    if(X == Y) return 0;
    int distance = 0;
    while(X != Y) {
        // if both nodes are not equal then move to the parent of the greater one.
        // parent of the node will always be given by node/2.
        // keep moving up until both arrive at a common parent.
        // with every move increase the distance by one.
        if(X > Y) X /= 2;
        else Y /= 2;
        distance++;
    }
    return distance;
  }
};