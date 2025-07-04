// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int res=0;
//         int m=mat.size();
//         int n=mat[0].size();

//         for(int row=0;row<m;row++){
//             for(int col=0;col<n;col++){
//                 if(mat[row][col]==0) continue;
//                 bool special=true;
//                 //check col
//                 for(int r=0;r<m;r++){
//                     if(r!=row && mat[r][col]==1){
//                         special=false;
//                         break;
//                     }
//                 }
//                 //check row
//                 for(int c=0;c<n;c++){
//                     if(c!=col && mat[row][c]==1){
//                         special=false;
//                         break;
//                     }
//                 }
//                 if(special==true){
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// }; 
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // int res=0;
        int m=mat.size();
        int n=mat[0].size();

        vector<int> rowcount(m,0); //how many 1s in a row
        vector<int> colcount(n,0); //how many 1s in a col

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==1){
                    rowcount[row]++;
                    colcount[col]++;
                }
            }    
        }
        int res=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==0) continue;
                if(rowcount[row]==1 && colcount[col]==1){
                    res++;
                }
            }
        }
        return res;
    }
};
