class Solution {
public:
    int KthLargest(vector<int> &arr, int k) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;//minheap
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};