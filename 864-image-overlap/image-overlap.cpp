#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int rowOff,int colOff){
        int n=img1.size();
        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //find indices of B frm A's indices
                int B_i=i+rowOff;
                int B_j=j+colOff;
                if(B_i<0|| B_i>=n|| B_j<0||B_j>=n) continue;
                if(img1[i][j]==1 && img2[B_i][B_j]==1){ //overlap
                    ctr++; 
                }
            }
        }
        return ctr;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxoverlap=0;
        for(int rowOff=-n+1;rowOff<n;rowOff++){
            for(int colOff=-n+1;colOff<n;colOff++){
                int ctr=countOverlaps(img1,img2,rowOff,colOff);
                maxoverlap=max(maxoverlap,ctr);
            }
        }
        return maxoverlap;
    }
};