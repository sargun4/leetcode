class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        priority_queue<p,vector<p>> pq;//maxheap- store top k smallest sum pairs {sum,(i,j)};
        //if heap size exceeds k, we remove the one with the largest sum
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){//for all pairs
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }else if(pq.top().first>sum){
                    pq.pop();//remove the worst pair-one w the largest sum among all the ones currently present in the pq
                    pq.push({sum,{i,j}});
                }else{
                //since arrs are sorted, future j will only increase the sum
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        //get all pairs frm heap
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