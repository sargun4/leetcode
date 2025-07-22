class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> cumulSum(n,0);
        cumulSum[0]=nums[0];
        for(int i=1;i<n;i++){
            cumulSum[i]=cumulSum[i-1]+nums[i];
        }
        vector<int> map(10001,-1);
        int res=0;
        int i=0; int j=0;
        while(j<n){
            i=max(i,map[nums[j]]+1);//jumping i so that i to j is valid
            //subarr sum i to j;
            int sum_till_j=cumulSum[j];
            int sum_till_i= i-1<0 ? 0: cumulSum[i-1];
            res=max(res,sum_till_j-sum_till_i);
            map[nums[j]]=j;
            j++;
        }
        return res;
    }
};
// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int n=nums.size();
//         unordered_set<int> st;
//         int i=0; int j=0;
//         int sum=0; int res=0;
//         while(j<n){
//             if(!st.count(nums[j])){
//                 sum+=nums[j];
//                 res=max(res,sum);
//                 st.insert(nums[j]);
//                 j++;
//             }else{//we hv seen this nums[j].So time to shrink the window
//                 while(i<n && st.count(nums[j])){
//                     sum-=nums[i];
//                     st.erase(nums[i]);
//                     i++;
//                 }
//             }
//         }
//         return res;
//     }
// };