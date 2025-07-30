typedef long long ll;
class Solution {
public:
    ll KthSmallest(ll arr[],ll n,ll k){
        priority_queue<ll> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
    long long sumBetweenTwoKth(long long arr[], long long n, long long k1, long long k2) {
        ll k1_smallest=KthSmallest(arr,n,k1);
        ll k2_smallest=KthSmallest(arr,n,k2);
        ll sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>k1_smallest && arr[i]<k2_smallest){
                sum+=arr[i];
            }
        }
        return sum;
    }
};