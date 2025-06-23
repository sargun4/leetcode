class Solution {
public:
    bool isPalindrome(string baseK){
        int i=0; int j=baseK.length()-1;
        while(i<=j){
            if(baseK[i]!=baseK[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string convertToBaseK(long long num,int k){
        if(num==0) return "0";
        string res="";
        while(num>0){
            res+=to_string(num%k);//convert num to base k
            num=num/k;
        }
        return res;
    }
    long long kMirror(int k, int n) {
        long long sum=0;
        int L=1;//creat L length palindromes
        while(n>0){
            //get palindromes
            int half_len=(L+1)/2;
            long long min_num=pow(10,half_len-1);
            long long max_num=pow(10,half_len)-1;
            for(int num=min_num;num<=max_num;num++){
                string first_half=to_string(num);
                string second_half=first_half;
                reverse(begin(second_half),end(second_half));

                string palind="";
                if(L%2==0){//even len palindrome
                    palind=first_half+second_half;
                }else{//odd
                    palind=first_half+second_half.substr(1);//leave 1st char of 2nd half
                }
                long long palind_num=stol(palind);
                string baseK=convertToBaseK(palind_num,k);
                if(isPalindrome(baseK)){
                    sum+=palind_num;//found 1 k-mirror num
                    n--;
                    if(n==0){break;}
                }
            }            
            L++;
        }
        return sum;
    }
};