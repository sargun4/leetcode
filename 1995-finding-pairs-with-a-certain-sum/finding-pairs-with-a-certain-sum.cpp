class FindSumPairs {
public:
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int,int>map;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1=nums1;
        vec2=nums2;
        for(int &x:vec2){
            map[x]++;
        }
    }
    //O(1)
    void add(int idx, int val) {
        map[vec2[idx]]--;
        vec2[idx]+=val;
        map[vec2[idx]]++;
    }
    int count(int tot) {
        int ctr=0;
        for(int &x:vec1){
            ctr+=map[tot-x];
        }
        return ctr;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(idx,val);
 * int param_2 = obj->count(tot);
 */