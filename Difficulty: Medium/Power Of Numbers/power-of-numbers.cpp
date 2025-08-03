class Solution {
public:
    int reverseExponentiation(int n){
        int rev=revNum(n);
        int p=pow(n,rev);
        return p;
    }
    int revNum(int n){
        int rev=0;
        while(n!=0){
            int rem=n%10;//last digit
            rev=rev*10+rem;//append digit to rev num
            n=n/10;//remove last digit frm og num
        }
        return rev;
    }
    int pow(int x,int n){
        if(n==0) return 1;
        if(n==1) return x;
        int half=pow(x,n/2);//rec
        if(n%2==0){//if pow is even
            return half*half;
        }else{//pow odd
            return half*half*x;
        }
    }
};