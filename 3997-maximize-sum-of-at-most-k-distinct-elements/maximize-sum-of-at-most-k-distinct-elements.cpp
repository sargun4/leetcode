class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;//minheap to keep largest k elmnts for max sum
        //set to avoid duplicates
        unordered_set<int> seen;
        for(auto num:nums){
            // Insert into pq only if it's not already there
            if(seen.find(num)==seen.end()){
                seen.insert(num);
                pq.push(num);
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            int num=pq.top();
            pq.pop();
            ans.push_back(num);
        }
        sort(ans.rbegin(),ans.rend());//desc
        return ans;
    }
};