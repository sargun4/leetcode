class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){//hand's size shd be a multiple of grpSize
            return false;
        }
        map<int,int> cardCtrMap;//{handno:freq};
        for(int &handno:hand){
            cardCtrMap[handno]++;
        }
        
        while(!cardCtrMap.empty()){
            //smallest available card
            int curr=cardCtrMap.begin()->first;
            //form a grp starting from curr of length groupSize
            for(int i=0;i<groupSize;i++){
                //if a card is missing or has exhausted its occurences
                if(cardCtrMap[curr+i]==0){
                    return false;//cant form valid grp
                }
                cardCtrMap[curr+i]--;
                if(cardCtrMap[curr+i]<1){
                    //remove card val if its occurences r exhausted
                    cardCtrMap.erase(curr+i);
                }
            }
        }
        return true;
    }
};