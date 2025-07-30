class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int> pq;//maxheap-max at top
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        vector<int> ans;
        while(k-- > 0 && !pq.empty()){
            int num=pq.top(); pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};