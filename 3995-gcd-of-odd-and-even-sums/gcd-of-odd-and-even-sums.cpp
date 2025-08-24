// gcd(n*n, (n+1)*n)=n
class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        else return gcd(b, a % b);
    }
    int gcdOfOddEvenSums(int n){
        int sumOdd=n*n;
        int sumEven=n*(n+1);
        return gcd(sumOdd,sumEven);
    }
};