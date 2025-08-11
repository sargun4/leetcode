class Solution {
public:
    int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> ans;
        //build powers arr
        for(int i=0;i<32;i++){
            if((n&(1<<i)) !=0){//ith bit is set
                powers.push_back(1<<i);
            }
        }
        for(auto&q:queries){
            int start=q[0];
            int end=q[1];
            long prod=1;
            for(int i=start;i<=end;i++){
                prod=(prod*powers[i])%mod;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};