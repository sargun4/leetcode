class Solution {
    public:
    void bfs(vector<vector<int>>& image, int sr, int sc,int original, int color){
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && image[nx][ny] == original){
                    image[nx][ny] = color;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        bfs(image,sr,sc,original,color);
        return image;
    }
};
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     bool isvalid(vector<vector<int>>&image,int i,int j,int n,int m,int color){
//         if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color){
//             return true;
//         }
//         return false;
//     }
//     void dfs(vector<vector<int>>&image,int i,int j,int n,int m,int color,int newcolor){
//         image[i][j]=newcolor;
//         if(isvalid(image,i+1,j,n,m,color))
//             dfs(image,i+1,j,n,m,color,newcolor);
//         if(isvalid(image,i-1,j,n,m,color))
//             dfs(image,i-1,j,n,m,color,newcolor);
//         if(isvalid(image,i,j+1,n,m,color))
//             dfs(image,i,j+1,n,m,color,newcolor);
//         if(isvalid(image,i,j-1,n,m,color))
//             dfs(image,i,j-1,n,m,color,newcolor);
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
//         int n=image.size();
//         int m=image[0].size();
//         int color=image[sr][sc];
//         if(color==newcolor) return image;
//         dfs(image,sr,sc,n,m,color,newcolor);
//         return image;
//     }
// };
// // class Solution {
// // private:
// //     void dfs(int row, int col, vector<vector<int>>&ans,
// //      vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
// //      int iniColor) {
// //         // color with new color
// //         ans[row][col] = newColor; 
// //         int n = image.size();
// //         int m = image[0].size(); 
// //         // there are exactly 4 neighbours
// //         for(int i = 0;i<4;i++) {
// //             int nrow = row + delRow[i]; 
// //             int ncol = col + delCol[i]; 
// //             // check for valid coordinate 
// //             // then check for same initial color and unvisited pixel
// //             if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
// //             image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
// //                 dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
// //             }
// //         }
// //     }
// // public:
// //     vector<vector<int>> floodFill(vector<vector<int>>& image, 
// //     int sr, int sc, int newColor) {
// //         // get initial color
// //         int iniColor = image[sr][sc]; 
// //         vector<vector<int>> ans = image; 
// //         // delta row and delta column for neighbours
// //         int delRow[] = {-1, 0, +1, 0};
// //         int delCol[] = {0, +1, 0, -1}; 
// //         dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
// //         return ans; 
// //     }
// // };