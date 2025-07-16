class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> indeg(n,0);
        long long maxval = LONG_MIN;//max indeg val
        int minidx=-1;
        for(int i=0;i<n;i++){
            indeg[edges[i]]+=i;
        }
        for(int i=0;i<n;i++){
            if(maxval<indeg[i]){
                maxval=indeg[i];
                minidx=i;
            }
        }
        return minidx;
    }
};