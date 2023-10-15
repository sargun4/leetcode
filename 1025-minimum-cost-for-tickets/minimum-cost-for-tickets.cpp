// #include <bits/stdc++.h>
// using namespace std;

// // //recur-tle
// // class Solution {
// // public:
// //     int solve(vector<int>& days, vector<int>& costs,int n,int i){
// //         if(i>=n) return 0; //cant travel anym0re so no cost
// //         //1 day pass
// //         int cost1=costs[0]+solve(days,costs,n,i+1);
// //         //7 days pass
// //         int j=i;
// //         int maxdays=days[i]+7;
// //         while(j<n && days[j]<maxdays){
// //             j++;
// //         }
// //         int cost7=costs[1]+solve(days,costs,n,j);
// //         //30 days pass
// //         j=i;
// //         maxdays=days[i]+30;
// //         while(j<n && days[j]<maxdays){
// //             j++;
// //         }
// //         int cost30=costs[2]+solve(days,costs,n,j);
// //         return min(cost1,min(cost7,cost30));
// //     }   
// //     int mincostTickets(vector<int>& days, vector<int>& costs) {
// //         int n=days.size();
// //         return solve(days,costs,n,0);
// //     }
// // };
// #include <bits/stdc++.h>
// using namespace std;
// //memo O(n)
// class Solution {
// public:
//     int  t[366];
//     int solve(vector<int>& days, vector<int>& costs,int n,int i){
//         if(i>=n) return 0; //cant travel anym0re so no cost
//         if(t[i]!=-1) return t[i];
//         //1 day pass
//         int cost1=costs[0]+solve(days,costs,n,i+1);
//         //7 days pass
//         int j=i;
//         int maxdays=days[i]+7;
//         while(j<n && days[j]<maxdays){
//             j++;
//         }
//         int cost7=costs[1]+solve(days,costs,n,j);
//         //30 days pass
//         j=i;
//         maxdays=days[i]+30;
//         while(j<n && days[j]<maxdays){
//             j++;
//         }
//         int cost30=costs[2]+solve(days,costs,n,j);
//         return t[i]=min(cost1,min(cost7,cost30));
//     }   
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n=days.size();
//         memset(t,-1,sizeof(t));
//         return solve(days,costs,n,0);
//     }
// };

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(begin(days),end(days));
        int lastday=days.back();
        vector<int> t(lastday+1,0);
        //t[i]=min cost to travel till day i of travel
        t[0]=0;
        for(int i=1;i<=lastday;i++){
            //check if we hv to ravel on ith day
            if(s.find(i)==s.end()){
                t[i]=t[i-1];
                continue;
            }
            t[i]=INT_MAX;
            int day1pass=costs[0]+t[max(i-1,0)];
            int day7pass=costs[1]+t[max(i-7,0)];
            int day30pass=costs[2]+t[max(i-30,0)];
            t[i]=min({day1pass,day7pass,day30pass});
        }
        return t[lastday];
    }
};