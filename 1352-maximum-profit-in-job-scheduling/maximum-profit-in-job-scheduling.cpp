#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int dp[50001];
    //find first job for which starting time >= currjob endtime
    int getNextIndex(vector<vector<int>> &arr,int l,int currJobEnd){
        int r=n-1;
        int res=n+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid][0]>=currJobEnd){ //we can take this task
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>> &arr,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int next=getNextIndex(arr,i+1,arr[i][1]);
        int taken=arr[i][2]+solve(arr,next);
        int nottaken=solve(arr,i+1);
        return dp[i]=max(taken,nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> arr(n,vector<int>(3,0)); // { {startTime1,endTime1,profit1},{startTime2,endTime2,profit2},..,{startTimen,endTimen,profitn} }
        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }
        auto comp=[&](auto &v1,auto &v2){
            return v1[0]<=v2[0];
        };
        //sort acc to start time
        sort(begin(arr),end(arr),comp);
        return solve(arr,0);
    }
};