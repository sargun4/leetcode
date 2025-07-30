class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans(n);
        priority_queue<int,vector<int>,greater<>> pq;//minheap
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                pq.push(arr[i]);
                ans[i]=-1;
                if(pq.size()==k){
                    ans[i]=pq.top();
                }
            }else{
                if(pq.top()<arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                }
                ans[i]=pq.top();
            }
        }
        return ans;
    }
};