class Solution {
public:
    bool isValid(int i,int j,int m,int n,vector<string> &matrix){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(matrix[i][j]=='#') return false;
        return true;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int minMoves(vector<string>& matrix) {
        int m=matrix.size(); int n=matrix[0].size();
        //map fr each teleporter char('A'-'Z') to all its coords
        unordered_map<char,vector<pair<int,int>>> charToCoordMap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='.' && matrix[i][j]!='#'){
                    charToCoordMap[matrix[i][j]].push_back({i,j});
                }
            }
        }

        if(matrix[m-1][n-1]=='#') return -1; //unreachable bottom right since its an obstcle
        //min heap-dijkstra
        using T=tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;//{moves,row,col}
        //dist matrix: min moves to reach each cell
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        unordered_set<char> used;//to track the char-use only once

        int moves=0;
        pq.push({moves,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            auto [currdist,x,y]=pq.top(); pq.pop();
            // int currdist=curr[0];
            // int x=curr[1];
            // int y=curr[2];
            if(currdist>dist[x][y]) continue;
            if(x==m-1 && y==n-1){//reache bottom right cell
                return currdist;
            }
            if(isupper(matrix[x][y]) && used.find(matrix[x][y]) == used.end()) {
                used.insert(matrix[x][y]);//mark teleport used
                for(auto &[nx,ny]: charToCoordMap[matrix[x][y]]) {
                    //teleport to all other matching letters at 0 cost
                    if((nx!=x|| ny!=y) && currdist<dist[nx][ny]) {
                            dist[nx][ny] = currdist;
                            pq.push({currdist, nx, ny});
                        }
                }
                // charToCoordMap.erase(matrix[x][y]); // clean up used teleporters
            }
            for(auto &d:dirns){
                int nr=x+d[0];//next
                int nc=y+d[1];
                if(isValid(nr,nc,m,n,matrix) && currdist+1<dist[nr][nc]){
                    dist[nr][nc]=currdist+1;
                    pq.push({currdist+1,nr,nc});
                }
            }
        }
        return -1;
    }
};