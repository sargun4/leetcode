class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0; int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            // checki if left half is sorted:
            if(nums[l]<=nums[mid]){
                if (nums[l] <= target && target < nums[mid]){
                    r=mid-1;//search in left half
                }else{
                    l=mid+1;//search in right half
                } 
            }
            else{// Right half is sorted
                if(nums[mid] < target && target <= nums[r]){
                    l=mid+1;//search in right half
                }else{
                    r=mid-1;//search in lefthalf
                }
            }
        }
        return -1; //Target not found
    }
};
