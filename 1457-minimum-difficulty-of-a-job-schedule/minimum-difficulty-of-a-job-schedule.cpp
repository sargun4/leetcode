#include <bits/stdc++.h>
using namespace std;
//MEMOIZATION
class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jd, int n,int idx,int d){
        //base case -if there is only 1 day left,then all jobs need to be done on
        //that day & find max difficulty of that day n return it
        if(d==1){
            int maxD=jd[idx];
            for(int i=idx;i<n;i++){
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }
        if(t[idx][d]!=-1){
            return t[idx][d];
        }
        int maxD=jd[idx];
        int finalres=INT_MAX;
        for(int i=idx;i<=n-d;i++){        
            maxD=max(maxD,jd[i]);
            int res=maxD+solve(jd,n,i+1,d-1);
            finalres=min(finalres,res);
        }
        return t[idx][d]=finalres;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d) return -1;
        memset(t,-1,sizeof(t));
        return solve(jd,n,0,d);
    }
};