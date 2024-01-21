class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
        vector<vector<int>> res;
		vector<int> v;
		subsetsWithDup(res, nums, v, 0);
		return res;
    }
private:
	void subsetsWithDup(vector<vector<int> > &res, vector<int> &nums, vector<int> &v, int begin) {
		res.push_back(v);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { 
				v.push_back(nums[i]);
				subsetsWithDup(res, nums, v, i + 1);
				v.pop_back();
			}
	}
};
// class Solution {
// public:
//     vector<vector<int> > subsets(vector<int> &nums) {
// 		sort(nums.begin(), nums.end());
//         vector<vector<int> > res;
// 		vector<int> v;
// 		subsets(res, nums, v, 0);
// 		return res;
//     }
// private:
// 	void subsets(vector<vector<int> > &res, vector<int> &nums, vector<int> &v, int begin) {
// 		res.push_back(v);
// 		for (int i = begin; i != nums.size(); ++i) {
// 			v.push_back(nums[i]);
// 			subsets(res, nums, v, i + 1);
// 			v.pop_back();
// 		}
// 	}
// };