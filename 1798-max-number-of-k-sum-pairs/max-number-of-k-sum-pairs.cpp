class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map; //{x:freq}
        int ctr=0;
        for(int x:nums){
            int rem=k-x;
            if(map[rem]>0){
                ctr++;
                map[rem]--;
            }else{
                map[x]++;
            }
        }
        return ctr;
    }
};
//if complement exists in the hashmap & ctr > 0:
// if a valid pair, increment ctr & decrease the frequency of the complement
// else, store or increment frequency of i in the hashmap