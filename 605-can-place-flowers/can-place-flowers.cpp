#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l=flowerbed.size();
        if(n==0){
            return true;
        }
        for (int i = 0; i < l; ++i) {
            if (flowerbed[i] == 0){
                bool leftempty=(i==0)||(flowerbed[i-1]==0);
                bool rightempty=(i==l-1)||(flowerbed[i+1]==0);
                if(leftempty  && rightempty){
                    flowerbed[i]=1;
                    n--;
                    if(n==0){
                        return true;
                    }
                }
            } 
        }
        return false;
    }
};