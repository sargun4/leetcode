using ll=long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();//3*n
        int n=N/3;
        vector<ll> leftMinSum(N,0);
        vector<ll> rightMaxSum(N,0);

        priority_queue<int> maxheap;
        ll lsum=0;
        for(int i=0;i<2*n;i++){
            maxheap.push(nums[i]);
            lsum+=nums[i];
            if(maxheap.size()>n){//if exceeds size n,remove largest frm maxheap top
                lsum-=maxheap.top();
                maxheap.pop();
            }
            leftMinSum[i]=lsum;
        }

        priority_queue<int,vector<int>,greater<int>> minheap;
        ll rsum=0;
        for(int i=N-1;i>=n;i--){
            minheap.push(nums[i]);
            rsum+=nums[i];
            if(minheap.size()>n){//if exceeds size n,remove smallest frm minheap's top
                rsum-=minheap.top();
                minheap.pop();
            }
            rightMaxSum[i]=rsum;
        }
        ll ans=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            ans=min(ans,leftMinSum[i]-rightMaxSum[i+1]);
        }
        return ans;
    }
};