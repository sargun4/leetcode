#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();       
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};     
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';        
        int steps = 0;        
        while (!q.empty()) {
            int size = q.size();            
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();                
                if (steps > 0 && (row != entrance[0] || col != entrance[1]) && (row == 0 || row == m - 1 || col == 0 || col == n - 1)) {
                    return steps;
                }               
                for (const auto& dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];                   
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == '.') {
                        q.push({newRow, newCol});
                        maze[newRow][newCol] = '+';
                    }
                }
            }            
            steps++;
        }
        return -1;
    }
};
