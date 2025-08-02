class Solution {
public:
    
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> map;
        int minelmnt=INT_MAX;
        for(int &x:basket1){
            map[x]++;
            minelmnt=min(minelmnt,x);
        }
        for(int &x:basket2){
            map[x]--;
            minelmnt=min(minelmnt,x);
        }
        vector<int> ans;
        for(auto&it:map){
            int cost=it.first;
            int freq=it.second;
            if(freq==0){
                continue;
            }
            if(freq%2!=0){
                return -1;
            }
            for(int c=1;c<=abs(freq)/2;c++){
                ans.push_back(cost);
            }
        }
        sort(begin(ans),end(ans));
        long long res=0;
        for(int i=0;i<ans.size()/2;i++){
            res+=min(ans[i],minelmnt*2);
        }
        return res;
    }
};