class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int noofrounds=k/n;
        int idx=k%n;
        if(noofrounds%2==0){
            return idx;//goleft
        }else{
            return n-idx;//right
        }
        
    }
};