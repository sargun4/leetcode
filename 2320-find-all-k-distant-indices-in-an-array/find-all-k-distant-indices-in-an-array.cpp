class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> res;
        int lastAdded=-1;//the last idx added to avoid duplicates
        for (int j=0;j<n;j++) {
            if (nums[j]==key) {
                int start=max(0,j-k);
                int end=min(j+k,n-1);
                //skippin alr added indices
                if (!res.empty() && lastAdded>=start){
                    start=lastAdded+1;
                }
                for(int i=start;i<=end;i++){
                    res.push_back(i);
                    lastAdded=i;
                }
            }
        }
        return res;
    }
};
