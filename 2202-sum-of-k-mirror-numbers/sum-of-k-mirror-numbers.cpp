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
    //convet num to base k
    string convertToBaseK(long long num,int k){
        if(num==0) return "0";
        string res="";
        while(num>0){
            res+=to_string(num%k);//add curr digit
            num=num/k;//move to next digit
        }
        return res;
    }
    long long kMirror(int k, int n) {
        long long sum=0;//sum of k-mirror numbers found so far
        int L=1;//creat L length palindromes-start checkin w len=1
        while(n>0){//Keep searching until we've found 'n' k-mirror numbers
            //get palindromes
            int half_len=(L+1)/2;//Half len needed to generate L-digit palindrome
            //generate the min n max nos for the 1st half;
            //eg-for L=3 -> half_len=2, min_num=10, max_num=99
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
                long long palind_num=stoll(palind);//Convert the string to long long
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