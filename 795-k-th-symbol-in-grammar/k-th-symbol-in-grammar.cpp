// T-O(n)
// S-O(n)
class Solution {
public:
    int kthGrammar(int n, int k) {
         if(n==1) return 0;
         int mid=(1<<(n-2));
        // or//  int mid=2^(n-2);
        if(k<=mid){ //if k is in first half
            return kthGrammar(n-1,k);
        }else{//if k is in second half
            return !kthGrammar(n-1,k-mid);
        }
    }
};