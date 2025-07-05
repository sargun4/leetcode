class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>> pq;//{fracn,arr[i],arr[j]};
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double fracn=(double) arr[i]/arr[j];
                pq.push(vector<double>{fracn,(double)arr[i],(double)arr[j]});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<int>ans(2);
        auto vec=pq.top();
        int ith=vec[1];
        int jth=vec[2];
        ans[0]=ith;
        ans[1]=jth;
        return ans;
    }
};