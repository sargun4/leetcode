#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m=1000000007;
    int t[1001];
    int solve(int n) {
        if(n==1||n==2) return n;
        if(t[n]!=-1)return t[n];
        if (n==3) return 5;
        return t[n]=(2*solve(n-1)%m+solve(n-3)%m)%m;
    }
    int numTilings(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};