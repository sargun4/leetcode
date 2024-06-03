class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m=s.length();
        int n=t.length();
        int sptr=m-1;
        int tptr=n-1;
        int sskips=0;
        int tskips=0;
        while(sptr>=0||tptr>=0){
            while(sptr>=0){
                if(s[sptr]=='#'){
                    sskips+=1;
                    sptr-=1;
                }else if(sskips>0){
                    sptr-=1;
                    sskips-=1;
                }else{
                    break;
                }
            }
            while(tptr>=0){
                if(t[tptr]=='#'){
                    tskips+=1;
                    tptr-=1;
                }else if(tskips>0){
                    tptr-=1;
                    tskips-=1;
                }else{
                    break;
                }
            }
            if(sptr>=0 && tptr>=0 && s[sptr]!=t[tptr]){
                return false;
            }
            if((sptr>=0)!=(tptr>=0)){
                return false;
            }
            sptr-=1;
            tptr-=1;
        }
        return true;
    }
};