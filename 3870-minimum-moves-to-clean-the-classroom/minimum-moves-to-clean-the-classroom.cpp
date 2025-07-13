// State Space = O(M * N * E * 2^L)
// M*N = grid size
// E = energy levels
// 2^L = all subsets of litter collected
// Time Complexity = same as state space, because each unique state is processed once in BFS.
// Space Complexity = for dist + queue = O(M*N*E*2^L)
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int sx=-1; int sy=-1;
        vector<pair<int,int>> litter_item_coords;//stores all litter coords
        map<pair<int,int>, int> litter_coord_to_idx_map;//{litter_posn:bitmask_idx}
        //1. Parse the grid to find start point and litter coordinates
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){//get start coords
                    sx=i;
                    sy=j;
                }else if(classroom[i][j]=='L'){
                    litter_coord_to_idx_map[{i,j}]=litter_item_coords.size();
                    litter_item_coords.push_back({i, j});
                }
            }
        }
        int num_litter=litter_item_coords.size();//total litter to collect
        if(num_litter==0)//if no litter to collect
            return 0;
        //target bitmask where all bits = 1 (all litter collected)
        int target_mask=(1<<num_litter)-1;
        //2. declare a 4D DP state array
        // dist[x][y][e][mask] = minimum moves to reach cell (x,y) with energy `e` and litter bitmask `mask`
        vector<vector<vector<vector<int>>>> dist(m,vector<vector<vector<int>>>(n,vector<vector<int>>(energy+1,vector<int>(1<<num_litter,-1))));

        queue<tuple<int, int, int, int>> q; //state-{x,y,energy_left,litter_mask};
        dist[sx][sy][energy][0]=0;//starting at (sx,sy) w enrgy & litter=0 collected
        q.push({sx,sy,energy,0});
        //bfs
        while (!q.empty()) {
            auto [x,y,curr_energy,mask] = q.front();
            q.pop();
            int moves = dist[x][y][curr_energy][mask];
            //if all litter collected, return moves
            if (mask==target_mask){
                return moves;
            }
            //4dirns
            for(int i=0;i<4;i++){
                int nx=x+dirns[i][0];
                int ny=y+dirns[i][1];
                //check bounds and obstacle
                if (isValid(nx,ny,m,n) && classroom[nx][ny]!='X'){
                    if (curr_energy>0){//only move if we hv energy
                        int energy_after_move=curr_energy-1; //energy cost of 1 per move
                        int next_total_moves=moves+1;
                        int energy_at_new_cell=energy_after_move;//updated energy after move
                        int new_mask_after_move=mask;//updated litter collection status
                        char dest_cell_char=classroom[nx][ny];
                        if(dest_cell_char=='L'){//if new cell has litter, update mask
                            int litter_idx=litter_coord_to_idx_map.at({nx, ny});
                            new_mask_after_move |= (1 << litter_idx);//collect litter by setting the bit
                        }
                        if(dest_cell_char=='R'){//if new cell is recharge station, restore energy
                            energy_at_new_cell=energy;
                        }
                        //only process this state if it hasn't been visited or can be optimized
                        if(dist[nx][ny][energy_at_new_cell][new_mask_after_move] == -1 || next_total_moves < dist[nx][ny][energy_at_new_cell][new_mask_after_move]) {
                            dist[nx][ny][energy_at_new_cell][new_mask_after_move]=next_total_moves;
                            q.push({nx,ny,energy_at_new_cell,new_mask_after_move});
                        }
                    }
                }
            }
        }
        // If loop ends without collecting all litter, return -1
        return -1;
    }
};
