 
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxscore=0,score=0,i=0,j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                maxscore=max(maxscore,++score);
            }else if(score>0){
                score--;
                power+=tokens[j--];
            }else{
                break;
            }
        }
        return maxscore;
    }
};