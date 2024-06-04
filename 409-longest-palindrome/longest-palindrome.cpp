class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_set<char> set;
        int res=0;
        for(char &ch:s){
            if(set.count(ch)){//a;lready present
                res+=2;
                set.erase(ch);
            }else{
                set.insert(ch);
            }
        }
        if(!set.empty()){
            res++;
        }
        return res;
    }
};