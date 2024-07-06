class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l= 0;
        int r= nums.size()-1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid+1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

// In each iteration of the loop, the mid index is computed as the average of the left and right pointers. If the element at the mid index is greater than the element at the next index (i.e., nums[mid] > nums[mid+1]), then the peak element must be in the left half of the array, so the right pointer is updated to mid. Otherwise, the peak element must be in the right half of the array, so the left pointer is updated to mid+1.

// # At the end of the loop, the left pointer points to the peak element, so it is returned as the result.

// # This algorithm works because if the element at the mid index is not the peak element, then the array must be ascending to the right of the mid index (i.e., nums[mid] < nums[mid+1]). Therefore, the peak element must be in the right half of the array. Similarly, if the element at the mid index is greater than the element at the next index, then the array must be descending to the right of the mid index, so the peak element must be in the left half of the array. By repeating this process with the appropriate half of the array at each step, the algorithm converges on the peak element in O(log n) time.
