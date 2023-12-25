class Solution {
public:
    vector<int> dp;
    //memoization-TD
    int str_to_int(string s){
        if(s.size()==1) return s[0]-'0';
        return (s[0]-'0')*10+(s[1]-'0');
    }
    int f(string s,int idx){
        //base case;
        if(s[idx]=='0') return 0;
        if(idx>=s.size()) return 0;
        if(idx==s.size()-1){
            if(s[idx]=='0') return 0;
            else return 1;
        }
        if(idx==s.size()-2){
            bool canform2digits=str_to_int(s.substr(idx,2))<=26;
            return f(s,idx+1)+(canform2digits);
        }

        if(dp[idx]!=-1) return dp[idx];
        bool canform2digits=str_to_int(s.substr(idx,2))<=26;
        return dp[idx]=f(s,idx+1)+((canform2digits) ? f(s,idx+2):0);
    }
    int numDecodings(string s){
        dp.clear();dp.resize(105,-1);

        return f(s,0);
    }
};