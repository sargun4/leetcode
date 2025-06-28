class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        // vector of tuples: {digit_sum, val, original_idx}
        vector<tuple<int,int,int>> arr;
        for(int i=0;i<n;i++){
            int sum=digitSum(nums[i]);
            arr.emplace_back(sum,nums[i],i);
        }
        //sort tha arr by digitsum n break ties using val
        sort(arr.begin(),arr.end());
        //posn map
        vector<int>idx(n);//idx[i]=new posn of original elmnt at i
        for(int i=0;i<n;i++){
            idx[get<2>(arr[i])]=i;//get original_idx from sorted posn
        }
        //no of swaps counting using cycle detection
        vector<bool> vis(n,false);
        int swaps=0;
        for(int i=0;i<n;i++){
            //if elmnt alr vis or alr in correct place,skip
            if(vis[i] || idx[i]==i) continue;
            int cyclesize=0;
            int j=i;
            //visit entire cycle;
            while(!vis[j]){
                vis[j]=true;
                j=idx[j];//moveto where curr idx shd go
                cyclesize++;
            }
            if(cyclesize>1){
                swaps+=(cyclesize-1);
            }
        }
        return swaps;
    }
};