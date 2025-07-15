// Traverse the whole mat & store coords directly connected to the Pacific Ocean to qPO & perform a BFS trav frm all the coords in qPO & mark them visited in visPO
// Similarly, traverse the whole mat & store coords directly connected to the Atlantic Ocean to qAO & perform a BFS trav frm all the coords in qAO & mark them visAO
// Traverse the given mat heights & maintain the count of coords that are visited during both the traversals.

// We simulate reverse water flow frm the oceans because:
// Water flows frm higher or equal cells to lower ones.
// So, we simulate BFS frm ocean boundaries to all higher neighbors, marking where water can reach frm the ocean.
// Cells that can be reached by both BFS runs are our final answer.
using p= pair<int,pair<int,int>>;//{cell,{i,j}}
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void bfs(vector<vector<int>>&mat,queue<p>&q,vector<vector<int>> &vis,int m,int n){
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            int val=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            for(auto &d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
//only move to valid(inbound),unvis cells where ht >= current cell's height(val)
                if(isValid(nx,ny,m,n) && !vis[nx][ny] && mat[nx][ny]>=val){
                    vis[nx][ny]=1;
                    q.push({mat[nx][ny],{nx,ny}});
                }
            }
        }
    }
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    int countCoordinates(vector<vector<int> > &mat) {
        int m=mat.size();
        int n=mat[0].size();
        //2 vis n 2 queues
        vector<vector<int>> visPO(m,vector<int>(n,0));//pacific ocean vis
        vector<vector<int>> visAO(m,vector<int>(n,0));//atlantic ocean vis
        queue<p> qPO;//pacific ocean q to store cells frm which water can flow to pacific
        queue<p> qAO;//atlantic ocean queue to store cells frm which water can flow to atlantic
        //push boundary cells to respective queues and mark visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cell=mat[i][j];
                if(i==0||j==0){//top n left-Pacific
                    visPO[i][j]=1;
                    qPO.push({cell,{i,j}});
                }
                if(i==m-1||j==n-1){//bottom n right cell-atlantic
                    visAO[i][j]=1;
                    qAO.push({cell,{i,j}});
                }
            }
        }
        bfs(mat,qPO,visPO,m,n);
        bfs(mat,qAO,visAO,m,n);
        int ans=0;
        //cells reachable frm both oceans counted
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
//water frm (i,j) coords is reachable to both oceans
                if(visPO[i][j] && visAO[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};

