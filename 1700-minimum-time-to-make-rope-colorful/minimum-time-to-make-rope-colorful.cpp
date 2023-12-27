#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res=0,maxcost=0,sumcost=0,n=s.size();
        for(int i=0;i<n;i++){
            if(i>0 && s[i]!=s[i-1]){
                res+=sumcost-maxcost;
                sumcost=maxcost=0;
            }
            sumcost+=cost[i];
            maxcost=max(maxcost,cost[i]);
        }
        res+=sumcost-maxcost;
        return res;
    }
};