class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //diff array
        vector<int> diff(n+1,0);
        for (auto &b : bookings) {
            int l=b[0]-1;
            int r=b[1]-1;
            int val=b[2];//no of bookings
            diff[l]+=val;
            diff[r+1]-=val;
        }
        //build prefix sum to get final bookings
        int sum=0;
        for(auto &it:diff){
            sum+=it;
            it=sum;
        }
        diff.pop_back();
        return diff;
    }
};
//TLE
// class Solution {
// public:
//     vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//         map<int,int> map;
//         for(int i=0; i<bookings.size(); i++){
//             int idx1=bookings[i][0]; int idx2=bookings[i][1]; int wt=bookings[i][2];
//             for(int idx=idx1;idx<=idx2;idx++){
//                 map[idx]+=wt;
//             }
//         }
//         vector<int> ans(n,0);
//         for(int i=0;i<n;i++){
//             if(map[i+1])
//                 ans[i]=map[i+1];
//         }
//         return ans;
//     }
// };