using p=pair<int,pair<int,int>>;
class Solution {
public:
    bool isValid(int i,int j,int N,int M){
        return i>=0 && i<N && j>=0 && j<M;
    }
    void bfs(queue<p>&q,vector<vector<int>>&vis,vector<vector<int>> &mat,int N,int M){
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            int val=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            for(auto &d:dirns){
                int nx=x+d.first;
                int ny=y+d.second;
                if(isValid(nx,ny,N,M) && !vis[nx][ny] && mat[nx][ny]>=val){
                    vis[nx][ny]=1;
                    q.push({mat[nx][ny],{nx,ny}});
                }
            }
        }
    }
    vector<pair<int,int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    int water_flow(vector<vector<int>> &mat, int N, int M) {
        vector<vector<int>> visIO(N,vector<int>(M,0));//indian ocean
        vector<vector<int>> visAO(N,vector<int>(M,0));//arabian ocean
        queue<p> q1;//indian ocean queue
        queue<p> q2;//arabian ocean queue
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int cell=mat[i][j];
                if(i==0 || j==0){//top n left edges
                    q1.push({cell,{i,j}});
                    visIO[i][j]=1;
                }
                if(i==N-1 || j==M-1){//right n bottom edges
                    q2.push({cell,{i,j}});
                    visAO[i][j]=1;
                }
            }
        }
        bfs(q1,visIO,mat,N,M);
        bfs(q2,visAO,mat,N,M);
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(visIO[i][j] && visAO[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// class Solution{   
// public:
//     //Recursive function to perform depth-first search (DFS) 
//     //to mark the cells that can be reached by water flow from a given cell
//     void dfs(vector<vector<int>> &mat, vector<vector<bool>> &vis, int i, int j, int n, int m){

//         //Base case: If we are outside the grid or if the cell is already visited, return
//         if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return;
        
//         //Mark the cell as visited
//         vis[i][j] = true;
    
//         //Recursive calls to check the neighboring cells and mark them if they can be reached
//         //by water flow from the current cell
        
//         //Check the cell above
//         if(i>0 && !vis[i-1][j] && mat[i-1][j] >= mat[i][j]){
//             dfs(mat, vis, i-1, j, n, m);
//         }
        
//         //Check the cell below
//         if(i<n-1 && !vis[i+1][j] && mat[i+1][j] >= mat[i][j]){
//             dfs(mat, vis, i+1, j, n, m);
//         } 
        
//         //Check the cell to the left
//         if(j>0 && !vis[i][j-1] && mat[i][j-1] >= mat[i][j]){
//             dfs(mat, vis, i, j-1, n, m);
//         } 
        
//         //Check the cell to the right
//         if(j<m-1 && !vis[i][j+1] && mat[i][j+1] >= mat[i][j]){
//             dfs(mat, vis, i, j+1, n, m);
//         } 
//     }

//     //Function to calculate the number of cells that can be reached by water flow from Indian and Arabian Ocean
//     int water_flow(vector<vector<int>> &mat,int N,int M){

//         //Create two 2D vectors to track the cells that can be reached from Indian and Arabian Ocean
//         vector<vector<bool>> indian(N, vector<bool>(M, false));
//         vector<vector<bool>> arabian(N, vector<bool>(M, false));
    
//         //Mark the cells that can be reached from the Indian Ocean by performing DFS
//         //starting from the first column of the grid
//         for(int i=0;i<N;i++) dfs(mat, indian, i, 0, N, M);
        
//         //Mark the cells that can be reached from the Indian Ocean by performing DFS
//         //starting from the first row of the grid
//         for(int i=0;i<M;i++) dfs(mat, indian, 0, i, N, M);
        
//         //Mark the cells that can be reached from the Arabian Ocean by performing DFS
//         //starting from the last column of the grid
//         for(int i=0;i<N;i++) dfs(mat, arabian, i, M-1, N, M);
        
//         //Mark the cells that can be reached from the Arabian Ocean by performing DFS
//         //starting from the last row of the grid
//         for(int i=0;i<M;i++) dfs(mat, arabian, N-1, i, N, M);

//         //Count the no of cells that can be reached from both oceans and return the count
//         int count = 0;
//         for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++){
//                 if(indian[i][j] && arabian[i][j]){
//                     count++;
//                 }        
//             }
//         }
//         return count;
//     }
// };