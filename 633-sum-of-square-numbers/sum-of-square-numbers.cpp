#define ll long long int
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(ll a=0;a*a<=c;a++){
            ll b=sqrt(c-a*a);
            if(b*b==c-a*a) return true;
        }
        return false;
    }
};