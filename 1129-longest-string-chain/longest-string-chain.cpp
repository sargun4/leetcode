#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[1001][1001];
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    bool ispred(string &prev,string &curr){
        int M=prev.length();
        int N=curr.length();
        if(M>=N||N-M!=1){
            return false;
        }
        int i=0,j=0;
        while(i<M && j<N){
            if(prev[i]==curr[j]){
                i++;
            }j++;
        }
        return i==M;
    }
    int lis(vector<string>&words,int previdx,int curridx){
        if(curridx==n) return 0;
        if(previdx!=-1 && t[previdx][curridx]!=-1){
            return t[previdx][curridx];
        }
        int taken=0,nottaken=0;
        if(previdx==-1||ispred(words[previdx],words[curridx])){
            taken=1+lis(words,curridx,curridx+1);
        }
        nottaken=lis(words,previdx,curridx+1);
        if(previdx!=-1){
            t[previdx][curridx]=max(taken,nottaken);
        }
        return max(taken,nottaken);
    }

    int longestStrChain(vector<string>& words) {
        memset(t,-1,sizeof(t));
        n=words.size();
        sort(words.begin(), words.end(), compare);
        
        return lis(words,-1,0);
    }
};
// class Solution {
// public:
//     static bool compare(const string &s1, const string &s2) {
//         return s1.length() < s2.length();
//     }

//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(), compare);
//         unordered_map<string, int> dp;
//         int res = 0;
//         for (string w : words) {
//             for (int i = 0; i < w.length(); i++) {
//                 string pre = w.substr(0, i) + w.substr(i + 1);
//                 dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
//             }
//             res = max(res, dp[w]);
//         }
//         return res;
//     }
// };