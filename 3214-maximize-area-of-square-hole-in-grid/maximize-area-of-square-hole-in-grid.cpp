#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxH=0,maxV=0; 
        int hlen=hBars.size();
        for (int i = 0; i<hlen ; i++){
            int ctr=1;
            while(i+1<hlen && hBars[i]+1 == hBars[i+1]){
                i++;
                ctr++;
            }
            maxH=max(maxH,ctr);
        }

        int vlen=vBars.size();
        for (int i = 0; i<vlen ; i++){
            int ctr=1;
            while(i+1<vlen && vBars[i]+1 == vBars[i+1]){
                i++;
                ctr++;
            }
            maxV=max(maxV,ctr);
        }
        int val=min(maxV+1,maxH+1);
        return val*val;
    }
};