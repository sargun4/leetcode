#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
        int m=n;
        vector<vector<int>> mat(m,vector<int>(n));
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        int dir=0;
        int ctr=1;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    mat[top][i]=ctr++;
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=bottom;i++){
                    mat[i][right]=ctr++;
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                    mat[bottom][i]=ctr++;
                }
                bottom--;
            }
            if(dir==3){
                for(int i=bottom;i>=top;i--){
                    mat[i][left]=ctr++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return mat;
    }
};