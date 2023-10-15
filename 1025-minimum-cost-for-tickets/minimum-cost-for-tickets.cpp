// #include <bits/stdc++.h>
// using namespace std;

// //recur-tle
// class Solution {
// public:
//     int solve(vector<int>& days, vector<int>& costs,int n,int i){
//         if(i>=n) return 0; //cant travel anym0re so no cost
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
//         return min(cost1,min(cost7,cost30));
//     }   
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n=days.size();
//         return solve(days,costs,n,0);
//     }
// };
#include <bits/stdc++.h>
using namespace std;
//memo O(n)
class Solution {
public:
    int  t[366];
    int solve(vector<int>& days, vector<int>& costs,int n,int i){
        if(i>=n) return 0; //cant travel anym0re so no cost
        if(t[i]!=-1) return t[i];
        //1 day pass
        int cost1=costs[0]+solve(days,costs,n,i+1);
        //7 days pass
        int j=i;
        int maxdays=days[i]+7;
        while(j<n && days[j]<maxdays){
            j++;
        }
        int cost7=costs[1]+solve(days,costs,n,j);
        //30 days pass
        j=i;
        maxdays=days[i]+30;
        while(j<n && days[j]<maxdays){
            j++;
        }
        int cost30=costs[2]+solve(days,costs,n,j);
        return t[i]=min(cost1,min(cost7,cost30));
    }   
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(t,-1,sizeof(t));
        return solve(days,costs,n,0);
    }
};