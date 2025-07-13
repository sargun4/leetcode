#include <bits/stdc++.h>
using namespace std;
//using BFS
class Solution {
public:
    vector<vector<int>> dirn{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0||n==0||grid[0][0]!=0){
            return-1;
        }
        auto isSafe=[&](int x,int y){
            return (x>=0 && x<m && y>=0 && y<n);
        };
        queue<pair<int,int>> q;//{x,y}
        q.push({0,0});//start at top left cell
        grid[0][0]=1;
        int lvl=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
                if(x==m-1 && y==n-1){//reached bottom right cell
                    return lvl+1;
                }
                for(auto dir: dirn){///8dirns
                    int nrow=x+dir[0];
                    int ncol=y+dir[1];
                    if(isSafe(nrow,ncol)&& grid[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};

// #include <bits/stdc++.h>
// using namespace std;
// //using DIJKSTRA
// class Solution {
// public:
//     vector<vector<int>> dirn{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
//     typedef pair<int,pair<int,int>> p;
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         if(m==0||n==0||grid[0][0]!=0){
//             return-1;
//         }
//         auto isSafe=[&](int x,int y){
//             return (x>=0 && x<m && y>=0 && y<n);
//         };
//         vector<vector<int>> res(m,vector<int>(n,1e8));
//         priority_queue<p,vector<p>,greater<p>> pq; //min heap
//         pq.push({0,{0,0}});
//         res[0][0]=0;
//         while(!pq.empty()){
//             int d=pq.top().first;
//             pair<int,int> node=pq.top().second;
//             int x=node.first;
//             int y=node.second;
//             pq.pop();
//             for(auto dir:dirn){
//                 int nrow=x+dir[0];
//                 int ncol=y+dir[1];
//                 int dist=1;
//                 if(isSafe(nrow,ncol) && grid[nrow][ncol]==0 && d+dist<res[nrow][ncol]){
//                     pq.push({d+dist,{nrow,ncol}});                    
//                     res[nrow][ncol]=d+dist;
//                 }
//             }
//         }
//         if(res[m-1][n-1]==1e8){
//             return -1;
//         }
//         return res[m-1][n-1]+1;
//     }
// }; 