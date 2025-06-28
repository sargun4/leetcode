class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(sumOfDigits(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};