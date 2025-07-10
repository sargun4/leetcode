class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>> pq;//maxheap-{dist_frm_x,elmnt}
        for(int i=0;i<n;i++){
            int dist=abs(arr[i]-x);
            pq.push({dist,arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> distArr;
        while(!pq.empty()){
            auto [dist,elmnt]=pq.top();
            pq.pop();
            distArr.push_back(elmnt);
        }
        sort(begin(distArr),end(distArr));
        return distArr;
    }
};