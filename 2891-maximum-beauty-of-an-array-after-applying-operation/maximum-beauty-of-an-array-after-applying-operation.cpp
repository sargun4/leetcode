using p=pair<int,int>;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        //get max overlapping intervsls
        vector<p> intervals(n);
        for(int i=0;i<n;i++){
            intervals[i]={nums[i]-k,nums[i]+k};
        }
        sort(begin(intervals),end(intervals));

        deque<p> deq;
        int maxbeauty=0;
        for(p &interval:intervals){
            int curr_intrval_start=interval.first;
            while(!deq.empty() && deq.front().second<curr_intrval_start){//not overlapping
                deq.pop_front();//pop it
            }
            deq.push_back(interval);
            maxbeauty=max(maxbeauty,(int)deq.size());
        }
        return maxbeauty;
    }
};