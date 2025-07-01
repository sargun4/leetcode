class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.length();
        int i=0; 
        int balance=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                balance++;
            }else{//if =R
                balance--;
            }
            if(balance==0) ans++;
        }
        return ans;
    }
};