class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int n=s.size();
        if(n<10)
            return {};
        for(int i = 0; i<n-9; i++){
            string str = s.substr(i,10);
            mp[str]++;
        }
        vector<string> ans;
        for(auto x: mp){
            if(x.second > 1)
            ans.push_back(x.first);
        }
        
        return ans;
    }
};