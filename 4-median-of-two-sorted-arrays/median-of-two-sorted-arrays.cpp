class Solution {
public:
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    }
    return -1;
} 
};
// // Optimized Using: Two Pointer with Extra Space
//   // Time Complexity: O(m+n)
//   // Space Complexity: O(m+n)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//         // Create a single sorted by merging two sorted arrays
//         int n1=nums1.size();
//         int n2=nums2.size();
//         int i=0;
//         int j=0;
//         int lastindex=-1;
             
//         // Initialize a new array
//            vector<int>v(n1+n2,0);
        
//         while(i<n1&&j<n2)
//         {
//             if(nums1[i]<=nums2[j])
//                 v[++lastindex]=nums1[i++];
//             else
//                 v[++lastindex]=nums2[j++];
//         }
        
//         while(i<n1)
//             v[++lastindex]=nums1[i++];
//         while(j<n2)
//             v[++lastindex]=nums2[j++];
        
//     // Return the result
//         int n=n1+n2;
//         return n%2?v[n/2]:(v[n/2]+v[n/2-1])/2.0;
        
//     }
// };


// // // Brute Force:
// //                // 1.Merge Both Array
// //               // 2.Sort them
// //              // 3.Find Median
// //             // TIME COMPLEXITY: O(n)+O(nlogn)+O(n)
// //             // SPACE COMPLEXITY: O(1)
 
// // class Solution {
// // public:
// //     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// //        // Initialization some neccessary variables
// //         vector<int>v;
        
// //         // store the array in the new array
// //         for(auto num:nums1)   // O(n1)
// //             v.push_back(num);
        
// //         for(auto num:nums2)  // O(n2)
// //             v.push_back(num);
        
// //         // Sort the array to find the median
// //         sort(v.begin(),v.end());  // O(nlogn)
        
// //         // Find the median and Return it
// //         int n=v.size();  // O(n)
        
// //         return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
// //     }
// // };

