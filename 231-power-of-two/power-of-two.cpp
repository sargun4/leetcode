class Solution {
public:
    bool isPowerOfTwo(int n){
        if(n<=0) return false;//-ve so cant be power of 2
        if(n==1) return true;//keep dividing no by 2 till its not div by 2 anymore
        while(n%2==0){
            n=n/2;
        }
        //if n=1, the integer is a power of two else false...
        return n==1;
    }
};