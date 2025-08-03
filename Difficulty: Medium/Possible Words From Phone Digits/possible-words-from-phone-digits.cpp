
class Solution {
public:
    void solve(int idx,vector<int> &arr,vector<string>&ans,string&s,
    unordered_map<int,string>&map){
        if(idx==arr.size()){
            ans.push_back(s);
            return;
        }
        if(map.find(arr[idx])==map.end()){//for 1=""
            solve(idx+1,arr,ans,s,map);
            return;
        }
        int num=arr[idx];
        for(int j=0;j<map[num].size();j++){
            s.push_back(map[num][j]);
            solve(idx+1,arr,ans,s,map);
            s.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr){
        unordered_map<int,string> map;
        map[2] = "abc"; map[3] = "def"; map[4] = "ghi";
        map[5] = "jkl"; map[6] = "mno"; map[7] = "pqrs";
        map[8] = "tuv"; map[9] = "wxyz";
        vector<string> ans;
        string s;
        solve(0,arr,ans,s,map);
        return ans;
    }
};