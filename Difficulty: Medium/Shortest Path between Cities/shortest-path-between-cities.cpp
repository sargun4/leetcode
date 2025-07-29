class Solution {
public:
    int shortestPath(int x, int y) {
        int ctr=0;
        while(x!=y){
            if(x>y){
                x=x/2;
            }else{
                y=y/2;
            }
            ctr++;
        }
        return ctr;
    }
};