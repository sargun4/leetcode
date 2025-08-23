class Solution {
public:
    int minArea(int sr,int er,int sc,int ec,vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        int minrow=m;
        int maxrow=-1;
        int mincol=n;
        int maxcol=-1;
        for(int i=sr;i<er;i++){
            for(int j=sc;j<ec;j++){
                if(grid[i][j]==1){
                    minrow=min(minrow,i);
                    maxrow=max(maxrow,i);
                    mincol=min(mincol,j);
                    maxcol=max(maxcol,j);
                }
            }
        }
        int side1=(maxrow-minrow+1);
        int side2=(maxcol-mincol+1);
        return side1*side2;
    }
    int helper(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MAX;
    //1 horiz cut n 1 vert cut to get 3 rects
        for(int rowsplit=1;rowsplit<m;rowsplit++){
            for(int colsplit=1;colsplit<n;colsplit++){
                int top=minArea(0,rowsplit,0,n,grid);
                int bottomleft=minArea(rowsplit,m,0,colsplit,grid);
                int bottomright=minArea(rowsplit,m,colsplit,n,grid);
                ans=min(ans,top+bottomleft+bottomright);

                int topleft=minArea(0,rowsplit,0,colsplit,grid);
                int topright=minArea(0,rowsplit,colsplit,n,grid);
                int bottom=minArea(rowsplit,m,0,n,grid);
                ans=min(ans,topleft+topright+bottom);
            }
        }
 //2 horizontal cuts to get 3 rects
        for(int split1=1;split1<m;split1++){
            for(int split2=split1+1;split2<m;split2++){
                int top=minArea(0,split1,0,n,grid);
                int mid=minArea(split1,split2,0,n,grid);
                int bottom=minArea(split2,m,0,n,grid);
                ans=min(ans,top+mid+bottom);
            }
        }
        return ans;
    }
    vector<vector<int>> rotateCW(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> rotatedGrid(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rotatedGrid[j][m-i-1]=grid[i][j];
            }
        }
        return rotatedGrid;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int ans=helper(grid);
        vector<vector<int>> rotatedGrid=rotateCW(grid);
        ans=min(ans,helper(rotatedGrid));
        return ans;
    }
};