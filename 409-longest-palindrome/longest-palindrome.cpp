class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,int> map;
        int res=0;
        int oddfreq=0;
        for(char &ch:s){
            map[ch]++;
            if(map[ch]%2!=0){
                oddfreq++;
            }else{
                oddfreq--;
            }
        }
        if(oddfreq>0){
            return n-oddfreq+1;
        }
        return n;
    }
};
// class Solution {
// public:
//     int longestPalindrome(string s) {
//         int n=s.length();
//         unordered_set<char> set;
//         int res=0;
//         for(char &ch:s){
//             if(set.count(ch)){//a;lready present
//                 res+=2;
//                 set.erase(ch);
//             }else{
//                 set.insert(ch);
//             }
//         }
//         if(!set.empty()){
//             res++;
//         }
//         return res;
//     }
// };