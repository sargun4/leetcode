#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int starting=intervals[0][0];
        int ending=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ending){
                ending=max(ending,intervals[i][1]); 
            }else{
                ans.push_back({starting,ending});
                starting=intervals[i][0];
                ending=intervals[i][1];
            }
        }
        ans.push_back({starting,ending});
        return ans;
    }
};