class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        int n=s.length();
        solve(s,result,n,0);
        return result;
    }
    void solve(string& s,vector<string>& result,int n,int idx){
        if(n==0){
            result.push_back(s);
        }else if(isalpha(s[idx])){
            s[idx]=toupper(s[idx]);
            solve(s,result,n-1,idx+1);
            s[idx]=tolower(s[idx]);
            solve(s,result,n-1,idx+1);
        }else{
            solve(s,result,n-1,idx+1);
        }
    }
};