class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        unordered_map<int,string> map;
        for(int i=0;i<n;i++){
            map[heights[i]]=names[i];
        }
        sort(heights.begin(),heights.end());

        vector<string> res(n);
        int idx = 0;
        for(int i = n - 1; i >= 0; i--) {
            res[idx++] = map[heights[i]];
        }
        return res;
    }
};