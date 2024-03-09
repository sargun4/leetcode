class Solution {
public:
    bool binsearch(vector<int>&nums,int target){
        int l=0; int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int &num:nums1){
            if(binsearch(nums2,num)){
                return num;
            }
        }
        return -1;
    }
};
// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> set(begin(nums1),end(nums1));
//         for(int &num:nums2){
//             if(set.find(num)!=set.end()){
//                 return num;
//             }
//         }
//         return -1;
//     }
// };