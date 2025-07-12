class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left=firstPlayer;//p1
        int right=secondPlayer;//p2
        if(left==n-right+1){//1st round only, they compete
            return {1,1};
        }
        if(left>n-right+1){
            int temp=n-left+1;
            left=n-right+1;
            right=temp;
        }
        int minround=n;
        int maxround=1;
        int nextRoundPlayersCount=(n+1)/2;
        if(right<=nextRoundPlayersCount){//case1- both players on same side
            int leftctr=left-1;
            int midctr=right-left-1;
            for(int survivorsLeft=0; survivorsLeft<=leftctr; survivorsLeft++){
                for(int survivorsMid=0; survivorsMid<=midctr; survivorsMid++){
                    int pos1=survivorsLeft+1;
                    int pos2=pos1 + survivorsMid + 1;
                    vector<int> tempRes=earliestAndLatest(nextRoundPlayersCount,pos1,pos2);
                    minround=min(minround,tempRes[0]+1);
                    maxround=max(maxround,tempRes[1]+1);
                }
            }
        }else{//case2- players on opp side of mid val
            int fightsRight=n-right+1;
            int leftctr=left-1;
            int midctr=fightsRight-left-1;
            int remainMidctr=right-fightsRight-1;
            for(int survivorsLeft=0; survivorsLeft<=leftctr; survivorsLeft++){
                for(int survivorsMid=0; survivorsMid<=midctr; survivorsMid++){
                    int pos1=survivorsLeft+1;
                    int pos2=pos1 + survivorsMid + (remainMidctr+1)/2 + 1;
                    vector<int> tempRes=earliestAndLatest(nextRoundPlayersCount,pos1,pos2);
                    minround=min(minround,tempRes[0]+1);
                    maxround=max(maxround,tempRes[1]+1);
                }
            }
        }
        return {minround,maxround};
    }
};