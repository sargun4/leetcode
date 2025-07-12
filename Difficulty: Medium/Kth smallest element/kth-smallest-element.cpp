class Solution {
  public:
    int kthSmallest(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int> pq;//maxheap
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
