class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mintime=INT_MAX;
        for(auto arr:tasks){
            int s=arr[0];
            int t=arr[1];
            mintime=min(mintime,s+t);
        }
        return mintime;
    }
};