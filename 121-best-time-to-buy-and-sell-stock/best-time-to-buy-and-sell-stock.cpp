#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=1,max_profit=0,min_price=prices[0];
        int n=prices.size();
        while(i<n){
            if(prices[i]<min_price){
                min_price=prices[i];
            }else{
                max_profit=max(max_profit,prices[i]-min_price);
            }
            i++;
        }
        return max_profit;
    }
};