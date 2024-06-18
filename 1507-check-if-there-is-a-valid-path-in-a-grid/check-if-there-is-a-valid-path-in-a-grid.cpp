class Solution {
    int m , n;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = -grid[0][0];
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<vector<int>>> mp(7, vector<vector<int>> (4 , vector<int>(7, 0)));

        // 1 , 0
        mp[1][0][1] = 1;
        mp[1][0][4] = 1;
        mp[1][0][6] = 1;

        // 1 , 1
        mp[1][1][1] = 1;
        mp[1][1][3] = 1;
        mp[1][1][5] = 1;

        // 2 , 2
        mp[2][2][2] = 1;
        mp[2][2][3] = 1;
        mp[2][2][4] = 1;

        // 2 , 3
        mp[2][3][2] = 1;
        mp[2][3][5] = 1;
        mp[2][3][6] = 1;

        //3 0
        mp[3][0][1] = 1;
        mp[3][0][4] = 1;
        mp[3][0][6] = 1;

        //3 3
        mp[3][3][2] = 1;
        mp[3][3][5] = 1;
        mp[3][3][6] = 1;
        
        // 4 1
        mp[4][1][1] = 1;
        mp[4][1][3] = 1;
        mp[4][1][5] = 1;
        

        // 4 3
        mp[4][3][2] = 1;
        mp[4][3][5] = 1;
        mp[4][3][6] = 1;

        // 5 0
        mp[5][0][1] = 1;
        mp[5][0][4] = 1;
        mp[5][0][6] = 1;

        // 5 2
        mp[5][2][2] = 1;
        mp[5][2][2] = 1;
        mp[5][2][4] = 1;

        // 6 1
        mp[6][1][1] = 1;
        mp[6][1][3] = 1;
        mp[6][1][5] = 1;

        // 6 2
        mp[6][2][2] = 1;
        mp[6][2][3] = 1;
        mp[6][2][4] = 1;


        while(!q.empty()){
               int x = q.front().first;
               int y = q.front().second;
               int pos = -grid[x][y];
               q.pop();
               if(x == m-1 && y == n-1)
               return true;
               // 0  -> Left       
               if(y-1>=0){
                   if(grid[x][y-1] > 0 && mp[pos][0][grid[x][y-1]]){
                       q.push({x,y-1});
                       grid[x][y-1] = -grid[x][y-1];
                   }               
                }   
               // 1  -> Right
               if(y+1 < n){
                   if(grid[x][y+1] > 0 && mp[pos][1][grid[x][y+1]]){
                       q.push({x,y+1});
                       grid[x][y+1] = -grid[x][y+1];
                   }               
                }   
               // 2   -> Up
               if(x-1>=0){
                   if(grid[x-1][y] > 0 && mp[pos][2][grid[x-1][y]]){
                       q.push({x-1,y});
                       grid[x-1][y] = -grid[x-1][y];
                   }
               }   
               // 3   ->  Down     
               if(x+1<m){
                   if(grid[x+1][y] > 0 && mp[pos][3][grid[x+1][y]]){
                       q.push({x+1,y});
                       grid[x+1][y] = -grid[x+1][y];
                   }               
                }   
        }
        return false;
    }
};
// class Solution {
// public:
    
//     bool hasValidPath(vector<vector<int>>& grid) 
//     {
//         int m = grid.size();
//         int n = grid[0].size();
//         if(m==1 and n==1) return true;
//         // 2D - direction vector for all streets
//         // 0th based indexing 0 to 11
        
//         // Let grid value g[i][j] = 4, means we need to follow "street-4" direction
//         // First index of street-4 direction = 2*(4-1) = 6
//         // Second index of street-4 direction = 2*(4-1)+1 = 7
//         // dir[6] = {0, 1}
//         // dir[7] = {1, 0}
//         vector<vector<int>>dir = {        // Indices   
//             {0,-1}, {0, 1}, // street 1  -->  0  1
//             {-1,0}, {1, 0}, // street 2  -->  2  3
//             {0,-1}, {1, 0}, // street 3  -->  4  5
//             {0, 1}, {1, 0}, // street 4  -->  6  7
//             {0,-1}, {-1,0}, // street 5  -->  8  9 
//             {0, 1}, {-1,0}  // street 6  -->  10  11
//         };

//         vector<vector<bool>>vis(m, vector<bool>(n, false));
//         queue<pair<int,int>>q;
        
//         q.push({0, 0});
//         vis[0][0] = true;
        
//         while (!q.empty()) 
//         {
//             auto cur = q.front(); q.pop();

//             int r = cur.first;
//             int c = cur.second;
//             int val = grid[r][c] - 1; // grid values 1 to 6
            
//             if(r==m-1 and c==n-1) return true;
            
//             // 2 directions from every cell
//             for(int k=0;k<2;k++) // k = 0, k = 1
//             {
//                 int idx = 2*val+k;   // get index
//                 int nr = r + dir[idx][0];
//                 int nc = c + dir[idx][1];
//                 if (nr < 0 or nr >= m or nc < 0 or nc >= n or vis[nr][nc]==true) continue;
                
//                 //  for checking the back direction matches with current cell i.e forming path to next cell
//                 for(int x=0;x<2;x++)
//                 {
//                     int i = 2*(grid[nr][nc]-1)+x;   // get index
//                     if(r == nr+dir[i][0] and c == nc+dir[i][1]){
//                         vis[nr][nc] = true;
//                         q.push({nr, nc});
//                     }       
//                 }
//             }
//         }
//         return false;
//     }
// };