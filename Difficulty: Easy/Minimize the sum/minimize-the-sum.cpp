// User function Template for C++

class Solution {
  public:
    int minimizeSum(int n, vector<int> arr) {
        priority_queue<int,vector<int>,greater<int>> pq;//minheap-store min elmnts at top
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int ans=0;
        while(pq.size()>1){
            int x1=pq.top(); pq.pop();
            int x2=pq.top(); pq.pop();
            int sum=x1+x2;
            pq.push(sum);
            ans+=sum;
        }
        return ans;
    }
};