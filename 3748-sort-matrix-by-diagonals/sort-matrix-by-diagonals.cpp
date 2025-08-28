class Solution {
public:
    int n;
    void sortDiag(int r,int c,vector<vector<int>>&grid,bool asc){
        vector<int> vec;//store diag elmnts
        int i=r;
        int j=c;

        while(i<n && j<n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(asc){
            sort(begin(vec),end(vec));
        }else{
            sort(rbegin(vec),rend(vec));
        }
        i=r;
        j=c;
        for(int&val:vec){
            grid[i][j]=val;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        //bottom left triangle-dec order
        for(int row=0;row<n;row++){
            sortDiag(row,0,grid,false);
        }
        //top right-inc order;
        for(int col=1;col<n;col++){
            sortDiag(0,col,grid,true);
        }
        return grid;
    }
};