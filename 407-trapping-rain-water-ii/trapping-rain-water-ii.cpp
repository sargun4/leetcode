using p=pair<int,pair<int,int>>;
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        //minheap-{ht,{i,j}};
        priority_queue<p,vector<p>,greater<>> boundaryCells;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        //1. first, push bonudary cells into pq
        //left most col n right most col(0,n-1);
        for(int i=0;i<m;i++){
            for(int j : {0,n-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                vis[i][j]=true;
            }
        }
        //top most col n bottom most col(0,n-1);
        for(int j=0;j<n;j++){
            for(int i : {0,m-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                vis[i][j]=true;
            }
        }
        int water=0;
        while(!boundaryCells.empty()){
            p curr=boundaryCells.top(); boundaryCells.pop();
            int ht=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            //4 dirn neighs explore
            for(auto &d:dirns){
                int nx=x+d[0];
                int ny=y+d[1];
                if(isValid(nx,ny,m,n) && !vis[nx][ny]){
                    water+=max(ht-heightMap[nx][ny],0);
                    int maxwater=max(ht,heightMap[nx][ny]);
                    boundaryCells.push({maxwater,{nx,ny}});
                    vis[nx][ny]=true;
                }
            }
        }
        return water;
    }
};