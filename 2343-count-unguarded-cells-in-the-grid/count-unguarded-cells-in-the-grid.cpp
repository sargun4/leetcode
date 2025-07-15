class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> mat(m, vector<char>(n, '.'));

        //mark guards and walls
        for(auto&g:guards) mat[g[0]][g[1]] = 'G';
        for(auto&w:walls) mat[w[0]][w[1]] = 'W';
        vector<vector<int>> vis(m, vector<int>(n, 0)); //vis (guarded) cells
        vector<vector<int>> dirns = {{0,1},{0,-1},{1,0},{-1,0}};//4drins
        for (auto &g : guards) {
            int x = g[0], y = g[1];
            for (auto &d : dirns) {
                int nx = x + d[0];
                int ny = y + d[1];
                // Traverse in one direction until we hit wall or guard
                while (nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == '.') {
                    vis[nx][ny] = 1; // mark as guarded
                    nx += d[0];
                    ny += d[1];
                }
            }
        }
        int ctr = 0;
        //count unguarded ('.') and not vis (not seen by any guard)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == '.' && vis[i][j] == 0) {
                    ctr++;
                }
            }
        }
        return ctr;
    }
};
