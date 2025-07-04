//0-wall, 1-empty, other grid vals-prices
//pricing = [low, high]
//1.do bfs frm start cell- to get dist frm cells.
//2.Collect only those cells that r reachable (not blocked by walls) & hv a price within range[low, high]
//use a min-heap (priority queue) with a custom comparator to keep the top k highest-ranked items in this order:
//1.shorter distance
// 2.lower price
// 3.smaller row idx
// 4.smaller column idx
class Solution {
public:
    //comparator for min-heap
    struct compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            //lower distance has higher priority
            if (a[0] != b[0]) return a[0] < b[0];
            //lower price has higher priority
            if (a[1] != b[1]) return a[1] < b[1];
            //lower row index has higher priority
            if (a[2] != b[2]) return a[2] < b[2];
            //lower column index has higher priority
            return a[3] < b[3];
        }
    };
    bool isValid(int i,int j,int m,int n){//within bounds
        return i>=0 && j>=0 && j<n && i<m;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m=grid.size(); int n=grid[0].size();
        int sx=start[0]; int sy=start[1];
        int low=pricing[0]; int high=pricing[1];

        queue<pair<int,int>> q;//{x,y} coords
        q.push({sx,sy});
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[sx][sy]=true;
        int dist=0;
        //minheap-store {dist_frm_start,price,x,y};
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        
        while(!q.empty()){//
            int len=q.size();
            while(len--){
                auto curr=q.front(); q.pop();
                int x=curr.first; int y=curr.second;
                int cell_price=grid[x][y];

                if(cell_price!=1 && cell_price>=low && cell_price<=high){//not an empty cell and price falling in range [l,h]
                    pq.push({dist,cell_price,x,y});
                    if(pq.size()>k){//if elmnts in pq exceed k, remove lowest priority elmnt
                        pq.pop();
                    }
                }
                for(auto&d:dirns){//checkin all 4dirns
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(isValid(nx,ny,m,n) && !vis[nx][ny] && grid[nx][ny]!=0){//not out of bounds, unvis n not a wall
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                } 
            }
            dist++;//inc dist lvl for next bfs layer
        }
        vector<vector<int>> ans;
//extract top-k elmnts frm minheap
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int x=curr[2];
            int y=curr[3];
            ans.push_back({x,y});
        }
        reverse(ans.begin(),ans.end());//cuz heap pops lowest ranked first
        return ans;
    }
};