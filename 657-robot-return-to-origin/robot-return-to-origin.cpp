class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0; int y=0;
        for(char move:moves){
            if(move=='U'){
                y+=1;
            }else if(move=='D'){
                y-=1;
            }else if(move=='L'){
                x-=1;
            }else if(move=='R'){
                x+=1;
            }
        }
        return x==0 && y==0;
    }
};