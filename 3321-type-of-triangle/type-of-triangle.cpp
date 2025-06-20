class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        if((nums[0] + nums[1])<=nums[2]) return "none";
        if(s.size() == 1) return "equilateral";
        if(s.size() == 2) return "isosceles";
        return "scalene";
    }
};

// class Solution {
// public:
//     string triangleType(vector<int>& nums) {
//         if (nums[0] == nums[1] && nums[1] == nums[2])
//             return "equilateral";
//         else if ((nums[0] == nums[1] || nums[1] == nums[2] ||
//                   nums[0] == nums[2]) &&
//                  (nums[0] + nums[1] > nums[2]) &&
//                  (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1]))
//             return "isosceles";
//         else if (nums[0] != nums[1] && nums[1] != nums[2] &&
//                  nums[0] != nums[2] && (nums[0] + nums[1] > nums[2]) &&
//                  (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1]))
//             return "scalene";
//         return "none";
//     }
// };