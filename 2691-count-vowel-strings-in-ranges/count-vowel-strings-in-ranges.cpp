class Solution {
public:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q=queries.size();
        int n=words.size();
        vector<int> ans(q);
        vector<int> cumulSum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            char startchar=words[i][0];
            char endchar=words[i].back();
            if(isVowel(startchar) && isVowel(endchar)){
                sum++;
            }
            cumulSum[i]=sum;
        }

        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l>0)
                ans[i]=cumulSum[r]-cumulSum[l-1];
            else
                ans[i]=cumulSum[r]-0;
        }
        return ans;
    }
};