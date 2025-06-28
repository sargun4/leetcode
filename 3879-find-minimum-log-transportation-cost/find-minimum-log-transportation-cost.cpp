typedef long long ll;
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n == 0 || m == 0 || k == 0) return 0;
        if(k>=m && k>=n) return 0;//If both n and m are less than or equal to k, the logs already fit — no cut needed.
        ll mincost=0;
        if(m>k && n<=k){//if only the 1st log m exceeds k
            int len1=(m-k);
            int len2=k;
            mincost=(long)len1*len2;
        }else if(n>k && m<=k){
            int len1=n-k;
            int len2=k;
            mincost=(long)len1*len2;
        }
        return mincost;
    }
};