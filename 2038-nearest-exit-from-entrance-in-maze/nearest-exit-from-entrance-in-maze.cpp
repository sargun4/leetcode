#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();       
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};     
        queue<pair<int, int>> q; //q={r,c}
        int sr=entrance[0]; //startrow
        int sc=entrance[1]; //startcol
        q.push({sr, sc});
        maze[sr][sc] = '+';        
        int steps = 0;        
        while (!q.empty()) {
            int len = q.size();            
            while (len--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();                
                if (steps > 0 && (r != sr || c != sc) 
                && (r == 0 || r == m - 1 || c == 0 || c == n - 1)) { //if reached
                    return steps;
                }               
                for (const auto& dir : dirs) {
                    int nrow = r + dir[0];
                    int ncol = c + dir[1];                   
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && maze[nrow][ncol] == '.') {
                        q.push({nrow, ncol});
                        maze[nrow][ncol] = '+';
                    }
                }
            }            
            steps++;
        }
        return -1;
    }
};
