#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(); 
        int label=1;
        vector<pair<int,int>> cells(n*n+1);
        vector<int> cols(n);
        for(int i=0; i<n; i++) cols[i]=i;
        for(int row=n-1;row>=0;row--){
            for(int col:cols){
                cells[label++]={row,col};
            }
            reverse(cols.begin(),cols.end());
        }

        vector<int> dist(n*n+1,-1);
        dist[1]=0;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int next=curr+1;next<=min(curr+6,n*n);next++){
                auto [row,col]=cells[next];
                int dest=board[row][col] == -1 ?next:board[row][col];
                if(dist[dest]==-1){
                    dist[dest]=dist[curr]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};
// class Solution{
// public:
//     int n;
//     pair<int,int> getCoord(int num){
//         int RT=(num-1)/n; //Row from Top
//         int RB=(n-1)-RT;//Rowfrm Bottom
//         int col=(num-1)%n;
//         if((n%2==1 && RB%2==1)||(n%2==0 && RB%2==0)){
//             col=(n-1)-col;
//         }
//         return make_pair(RB,col);
//     }
//     int snakesAndLadders(vector<vector<int>>& board) {
//         n=board.size();
//         int steps=0;
//         queue<int> q;
//         vector<vector<bool>> vis(n,vector<bool>(n,false));
//         vis[n-1][0]=true;
//         q.push(1);
//         //bfs
//         while(!q.empty()){
//             int len=q.size();
//             while(len--){
//                 int x=q.front();
//                 q.pop();
//                 if(x==n*n){
//                     return steps;
//                 }
//                 for(int k=1;k<=6;k++){
//                     int val=x+k;
//                     if(val>n*n) break;

//                     pair<int,int> coord=getCoord(val);
//                     int r=coord.first;
//                     int c=coord.second;
//                     if(vis[r][c]==true) continue;
//                     vis[r][c]=true;
//                     if(board[r][c]==-1){
//                         q.push(val);
//                     }else{
//                         q.push(board[r][c]);
//                     }
//                 }
//             }
//             steps++;
//         }
//         return -1;
//     }
// };