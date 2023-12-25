#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> set;
        int ans=0;
        for(int i=1;set.size()<n;++i){
            if(set.find(k-i)==set.end()){
                set.insert(i);
                ans+=i;
            }
        }
        return ans;
    }
};