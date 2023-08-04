//bfs
class Solution {
public:
    //T: O(row * col)
    //S: O(col)
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int island_ctr = 0;
        for(int m = 0; m < grid.size(); ++m) {
            for(int n = 0; n < grid[0].size(); ++n) {
                if(grid[m][n] == '1') {
                    ++island_ctr;
                    std::queue<pair<int, int>> bfs_que;//<m, col>
                    grid[m][n] = '2';
                    bfs_que.push(make_pair(m, n));
                    while(!bfs_que.empty()) {
                        std::pair<int, int> visited_node = bfs_que.front();
                        bfs_que.pop();
                        for(auto d : dir) {
                            int next_row = visited_node.first + d.first;
                            int next_col = visited_node.second + d.second;
                            if(next_row >= 0 && next_row < grid.size() && next_col >= 0 && next_col < grid[0].size() && grid[next_row][next_col] == '1') {
                                grid[next_row][next_col] = '2';
                                bfs_que.push(make_pair(next_row, next_col));
                            }
                            
                        }
                    }
                }   
            }  
        }
        return island_ctr;
    }
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<m, col>
};

// class Solution {
// public:
//     //dfs + recursive
//     //T: O(row * col)
//     //S: O(row)
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.empty())
//             return 0;
//         int island_ctr = 0;
//         for(int m = 0; m < grid.size(); ++m) {
//             for(int n = 0; n < grid[0].size(); ++n) {
//                 if(grid[m][n] == '1') {
//                     ++island_ctr;
//                     dfs(grid, m, n);//use dfs to mark every grid = 2 which belongs to this island.
//                 }   
//             }  
//         }
//         return island_ctr;
//     }
// private:
//     //dfs to mark every grid in this island.
//     int dfs(vector<vector<char>>& grid, int m, int n) {
//         grid[m][n] = '2';
//         for(auto d : dir) {
//             int next_row = m + d.first;
//             int next_col = n + d.second;
//             if(next_row >= 0 && next_row < grid.size() && next_col >= 0 && next_col < grid[0].size() && grid[next_row][next_col] == '1') {
//                 dfs(grid, next_row, next_col);
//             }   
//         }
//         return 0;
//     }
// private:
//     vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<m, col>
// };