// //O(m*n) -brute force
// // class Solution {
// // public:
// //     int countNegatives(vector<vector<int>>& grid) {
// //         int m=grid.size();
// //         int n=grid[0].size();
// //         int res=0;
// //         for(int i=0;i<m;i++){
// //             for(int j=0;j<n;j++){
// //                 if(grid[i][j]<0){
// //                     res++;
// //                 }
// //             }
// //         }
// //         return res;
// //     }
// // };

// //O(m*logn)
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int res=0;
//         for(auto &row:grid){
//             int idx=upper_bound(begin(row),end(row),0,greater<int>())-begin(row);
//             res+=(n-idx);            
//         }
//         return res;
//     }
// };

//O(m+n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        int row=m-1;
        int col=0;
        while(row>=0 && col<n){
            if(grid[row][col]>=0){
                col++;;
            }else{
                res+=(n-col);
                row--;
            }
        }
        return res;
    }
};