class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        double sum;
        for(int x:nums){
            sum+=x;
        }
        double avg=sum/n;
        int ctr=1;
        while(true){
            if(ctr>avg && find(nums.begin(),nums.end(),ctr)==nums.end()){
                return ctr;
            }
            ctr++;
        }
    }
};