class Solution {
public:
    vector<string> colStates;//store all valid col states
    int MOD=1e9+7;
    vector<vector<int>> dp;//memo- dp[remCOls][prevIdx]
    //rec to generate all valid column states of height m
    void generateColStates(string curr,char prevChar,int l,int m){
        //l-currlen
        if(l==m){//if currlen = max no of rows
            colStates.push_back(curr);//add this valid coloring
            return;
        }
        for(char ch:{'R','G','B'}){
            if(ch==prevChar){//condn- no two adj cells can hv same color
                continue;//skip if same as prev
            }
            generateColStates(curr+ch,ch,l+1,m);
        }
    }
    //get no of valid grids
    int solve(int remainCols,int prevIdx,int m){
        //base case-no more cols left to fill- so 1 valid way only
        if(remainCols==0) return 1;
        if(dp[remainCols][prevIdx]!=-1){//alr computed
            return dp[remainCols][prevIdx];
        }
        int ways=0;
        string prevState=colStates[prevIdx];//prev col coloring
        //try placing every possible valid col state next;
        for(int i=0;i<colStates.size();i++){
            if(i==prevIdx) continue;//skip if same as prevState(horizontal constraint)
            string currState=colStates[i];
            bool valid=true;
            //check if curr col is valid horizontally with prev col  
            for(int j=0;j<m;j++){//iterating on currstate n prevstate
                if(prevState[j]==currState[j]){//same color in same row across col
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
        //step1-genrate all column states of ht m
        generateColStates("",'#',0,m);//#(random) as prev char 
        int totalStates=colStates.size();
        //step2-dp table: [n cols][totalStates for prev col]
        dp=vector<vector<int>>(n+1,vector<int>(totalStates+1,-1));
        //step3- try all possible col states for the 1st col
        int res=0;
        for(int i=0;i<colStates.size();i++){
            res=(res+solve(n-1,i,m))%MOD;
        }
        return res;
    }
};