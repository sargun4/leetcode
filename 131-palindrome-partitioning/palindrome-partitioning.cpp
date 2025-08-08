class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        vector<string> path;
        dfs(0,s,path,ans);
        return ans;
    }
    void dfs(int idx,string &s,vector<string>&path,vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }
        for(int j=idx;j<s.size();j++){
            if(ispalind(s,idx,j)){
                path.push_back(s.substr(idx,j-idx+1));
                dfs(j+1,s,path,ans);
                path.pop_back();
            }
        }
    }

    bool ispalind(string &s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
};