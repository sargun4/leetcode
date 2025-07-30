// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n=arr.size();
        // vector<int> subarrSums;
        priority_queue<int> pq;//maxheap-max at top
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                pq.push(sum);
            }
        }
        int ans;
        while(k-- >0 && !pq.empty()){
            int num=pq.top(); pq.pop();
            ans=num;
        }
        return ans;
    }
};