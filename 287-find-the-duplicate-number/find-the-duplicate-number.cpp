//slow n fast approch
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n=nums.size();
        int slow=0;int fast=0;
        do{
            slow=nums[slow]; //move 1 place
            fast=nums[nums[fast]]; //move 2 plaaces
        }while(slow!=fast);

        slow=0;
        while(slow!=fast){//now move 1 place each
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};//t- O(n),space -O(1)

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         unordered_map<int,int> m;
//         for(int i=0;i<n;i++){
//             m[nums[i]]+=1;
//             if(m[nums[i]]>1){
//                 return nums[i];
//             }
//         }
//         return n;
//     }
// };