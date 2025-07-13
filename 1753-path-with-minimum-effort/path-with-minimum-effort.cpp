//O(ElogV)
// T-O(n x m x 4 x log(n x m))  
using p=pair<int,pair<int,int>>;// pq= {diff,{row,col}}
class Solution {
public:
    bool isValid(int i,int j,int m,int n){//in bounds check
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<p,vector<p>,greater<>> pq;//minheap-{diff,{x,y}};
        vector<vector<int>> dist(m,vector<int>(n,1e9));//dist mat-stores min effort bw cells
        pq.push({0,{0,0}});
        dist[0][0]=0;//src effort=0
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int diff=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            if(x==m-1 && y==n-1) return diff;//reached bottom right cell
            for(auto &d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                if(isValid(nx,ny,m,n)){
                    //effort to move to next cell is max of:
                    // {new edge's cost, curr_effort}
                    int newEffort=max(abs(heights[x][y]-heights[nx][ny]),diff);
                    if(newEffort<dist[nx][ny]){//if this path has less effort than any prev found
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        return 0;//if unreachble
    }
};