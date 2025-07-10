#define p pair<int,pair<int,int>>
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n=queries.size();
        //maxheap
        priority_queue<p> pq;//{dist,{x,y}};
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int dist=abs(x)+abs(y);
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                ans[i]=pq.top().first;
            }
        }
        return ans;
    }
};