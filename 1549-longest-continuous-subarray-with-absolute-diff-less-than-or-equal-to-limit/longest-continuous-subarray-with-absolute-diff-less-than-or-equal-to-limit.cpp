class Solution {
public:
    typedef pair<int,int> p;
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        priority_queue<p,vector<p>> maxpq;//maxheap={elmnt,idx};
        priority_queue<p,vector<p>,greater<p>> minpq;//minheap={elmnt,idx};

        int i=0; int j=0;
        int maxlen=0;
        while(j<n){
            maxpq.push({nums[j],j});
            minpq.push({nums[j],j});
            while(maxpq.top().first - minpq.top().first > limit){
                i=min(maxpq.top().second, minpq.top().second)+1;
                while(maxpq.top().second<i){
                    maxpq.pop();
                }
                while(minpq.top().second<i){
                    minpq.pop();
                }
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};