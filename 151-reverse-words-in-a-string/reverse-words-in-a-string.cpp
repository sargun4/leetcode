class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        //rev whole string
        reverse(s.begin(),s.end());

        int i=0;
        //l n r would rev the indiv strings back to their orginal self
        int l=0; int r=0;
        while(i<n){
            while(i<n && s[i]!=' '){//till we dont find a space char
                s[r]=s[i];
                r++; i++;
            }
            if(l<r){//now rev indiv str bck to og self
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        s=s.substr(0,r-1);
        return s;
    }
};