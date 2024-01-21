#include <bits/stdc++.h>
using namespace std; 
// T-O(n^3)
// S-O(n^2)
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        // Create a 2D vector to represent distances between pairs of nodes
        vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
         // -every house has a street w its adjacent house/neighbor
        for (int i=2;i<=n;i++){
            int j=i-1;
            dist[i][i]=0;
            dist[j][j]=0;
            dist[i][j]=1;
            dist[j][i]=1;
        }
        if(x!=y){ // additional street given in q
            dist[x][y] = 1;
            dist[y][x] = 1;
        }
        //floyd warshall-O(n^3)-calc all-pairs shortest distances
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        // count freq of each distance in the distance matrix
        unordered_map<int,int> map;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map[dist[i][j]]++;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = map[i+1];
        }
        return ans;
    }
};