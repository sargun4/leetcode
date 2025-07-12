using p=pair<int,pair<int,int>>;
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p> pq;//minheap- for min dist on top of pq
        for(auto it:points){
            int x=it[0]; int y=it[1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int dist=curr.first; 
            int x=curr.second.first;
            int y=curr.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};