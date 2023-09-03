#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int N;
    unordered_map<string,double> map;
    vector<pair<int,int>> dirn={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double solve(int r,int c,int k){
        if(r<0||r>=N||c<0||c>=N){ //out of bounds
            return 0;
        }
        if(k==0){//0 steps
            return 1;
        }
        string key=to_string(k)+"_"+to_string(r)+"_"+to_string(c);
        if(map.find(key)!=map.end()){
            return map[key];
        }

        double ans=0;
        for(auto &dir:dirn){
            int nrow=r+dir.first;
            int ncol=c+dir.second;
            ans+=(double)solve(nrow,ncol,k-1);
        }
        return map[key]=(double)ans/(8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        N=n;
        return solve(row,column,k);
    }
};