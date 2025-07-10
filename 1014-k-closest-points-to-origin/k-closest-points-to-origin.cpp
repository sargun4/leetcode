class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<p> pq;//maxheap
        for(int i=0;i<n;i++){
            int x=points[i][0]; int y=points[i][1];
            int dist=x*x+y*y;//euclidean dist from (0,0)
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            auto curr=pq.top(); pq.pop();
            int x=curr.second.first; int y=curr.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};