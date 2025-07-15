class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int res=0;
        int maxtillnow=values[0]+0;//stores max val of (values[i]+i);
        for(int j=1;j<n;j++){
            int val1=values[j]-j;
            int val2=maxtillnow;
            res=max(res,val1+val2);
            maxtillnow=max(maxtillnow,values[j]+j);
        }
        return res;
    }
};