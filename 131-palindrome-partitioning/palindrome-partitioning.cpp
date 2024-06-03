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
        for(int end=idx;end<s.size();end++){
            if(ispalind(s,idx,end)){
                path.push_back(s.substr(idx,end-idx+1));
                dfs(end+1,s,path,ans);
                path.pop_back();
            }
        }
    }

    bool ispalind(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};