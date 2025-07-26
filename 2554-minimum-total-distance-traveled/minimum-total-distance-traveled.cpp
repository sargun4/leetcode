typedef long long ll;
class Solution {
public:
    //ri-curr robot idx, fi-curr factory posn idx,
    ll solve(int ri,int fi,vector<int> & robot,vector<int>&posns,vector<vector<ll>> &dp){
        if(ri>=robot.size()){//all robots covered
            return 0;//no more dist to be covered
        }
        if(fi>=posns.size()){//no factories left
            return 1e12;//invalid large cost
        }
        if(dp[ri][fi]!=-1){//memo check
            return dp[ri][fi];//alr computed state
        }
        //2choices-
        //assign robot ri to factory fi (incurs cost)
        ll take_curr_factory=abs(robot[ri]-posns[fi])+solve(ri+1,fi+1,robot,posns,dp);
        //OR skip factory fi and try next one (don’t assign now)
        ll skip=solve(ri,fi+1,robot,posns,dp);
        return dp[ri][fi] = min(take_curr_factory,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //step1-sort robot n factory by posn
        sort(begin(robot),end(robot));
        sort(begin(factory),end(factory));
        
        //step2(expand factory posns to avoid tracking of limit n easy rec)
    //so if a factory at position 3 has a limit of 2, it will appear twice in posns → [3, 3]
        vector<int> posns;
        for(int i=0;i<factory.size();i++){
            int posn=factory[i][0];
            int limit=factory[i][1];
            for(int j=0;j<limit;j++){
                posns.push_back(posn);
            }
        }
        int m=robot.size();
        int n=posns.size();
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1));
        //step3- cal rec frm 1st robot n 1st factory(idx=0)
        return solve(0,0,robot,posns,dp);
    }
};