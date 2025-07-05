class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        priority_queue<p,vector<p>> pq;//maxheap- store {sum,(i,j)};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){//for all pairs
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }else{//top sum is smaller than curr sum, so break
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int i=curr.second.first;
            int j=curr.second.second;
            ans.push_back({nums1[i],nums2[j]});
        }
        return ans;
    }
};