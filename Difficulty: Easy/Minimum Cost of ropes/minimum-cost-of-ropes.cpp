class Solution {
public:
    int minCost(vector<int>& arr) {
        //keep picking smallest 2 elmnts frm arr, add their sum to cost, push the 
        //new cost into arr and pop these 2 out frm pq
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;//minheap-for smallest rope at top
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int ans=0;
        while(pq.size()>1){
            int r1=pq.top(); pq.pop();//smallest rope extraxted
            int r2=pq.top(); pq.pop();//2nd smallest rope
            int cost=r1+r2;
            pq.push(cost);
            ans+=cost;
        }
        return ans;
    }
};