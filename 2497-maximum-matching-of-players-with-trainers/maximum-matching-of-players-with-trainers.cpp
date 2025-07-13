class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers){
        int m=players.size();
        int n=trainers.size();
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int ctr=0;
        int i=0; int j=0;
        while(i<m && j<n){
            if(players[i]> trainers[j]){
                j++;
            }else{//condn
                ctr++;
                i++;
                j++;
            }
        }
        return ctr;
    }
};