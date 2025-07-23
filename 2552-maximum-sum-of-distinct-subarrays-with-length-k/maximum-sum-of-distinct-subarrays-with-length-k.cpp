typedef long long ll;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll res=0; //store max sum of any valid subarray of size k
        ll currWindowSum=0;
        unordered_set<int> set;//track of unique elements in the current window
        int i=0;//left ptr
        int j=0;//right ptr
        // slidng window
        while(j<n){
            //check if nums[j] is alr present in curr window nums[i..j]
            // If nums[j] already exists in the current window, it means we have a duplicate and we need to remove elements from the left until nums[j] can be safely added
            while(set.count(nums[j])){//while nums[j] is present in set
                currWindowSum-=nums[i];//remove nums[i] frm window sum
                set.erase(nums[i]);//remove frm set
                i++;//left ptr moved ahead to shrink window
            }
            //now nums[j] is unique in the window, so we can add it
            currWindowSum+=nums[j];
            set.insert(nums[j]);

            if(j-i+1==k){//if curr window size=k
                // Valid subarray of size k with all unique elements
                res=max(res,currWindowSum);
                //before sliding the window fwd,remove nums[i] cuz window shifts left-so move left ptr
                currWindowSum-=nums[i];
                set.erase(nums[i]);
                i++;
            }
            j++;//expand window my incr right ptr
        }
        return res;
    }
};