typedef long long ll;
class Solution {
public:
    long long maxDiamonds(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int> pq;//minheap
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        ll ans=0;
        while(k-- >0 && !pq.empty()){
            ll num=pq.top();
            ans+=num;
            pq.push(num/2);
            pq.pop();
        }
        return ans;
    }
};