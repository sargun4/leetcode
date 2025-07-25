class Solution {
public:
    vector<string> colStates;
    int MOD=1e9+7;
    vector<vector<int>> dp;
    void generateColStates(string curr,char prevChar,int l,int m){
        //l-currlen
        if(l==m){//if currlen = max no of rows
            colStates.push_back(curr);
            return;
        }
        for(char ch:{'R','G','B'}){
            if(ch==prevChar){//condn- no two adj cellscan hv same color
                continue;
            }
            generateColStates(curr+ch,ch,l+1,m);
        }
    }
    int solve(int remainCols,int prevIdx,int m){
        if(remainCols==0) return 1;//base case
        if(dp[remainCols][prevIdx]!=-1){
            return dp[remainCols][prevIdx];
        }
        int ways=0;
        string prevState=colStates[prevIdx];
        for(int i=0;i<colStates.size();i++){
            if(i==prevIdx) continue;
            string currState=colStates[i];
            bool valid=true;
            for(int j=0;j<m;j++){//iteratign on currstate n prevstate
                if(prevState[j]==currState[j]){
                    valid=false;
                    break;
                }
            }
            if(valid){
                ways=(ways+solve(remainCols-1,i,m))%MOD;
            }
        }
        return dp[remainCols][prevIdx]= ways;
    }
    int colorTheGrid(int m, int n) {
        //step1-genrate column states
        generateColStates("",'#',0,m);
        int totalStates=colStates.size();
        dp=vector<vector<int>>(n+1,vector<int>(totalStates+1,-1));
        //step2
        int res=0;
        for(int i=0;i<colStates.size();i++){
            res=(res+solve(n-1,i,m))%MOD;
        }
        return res;
    }
};