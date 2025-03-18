class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,vector<string>> map;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            string sorted_str=temp;
            map[sorted_str].push_back(strs[i]);
        }
        for(auto it:map){
            ans.push_back(it.second);
        }
        return ans;
    }
};