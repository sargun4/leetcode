class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int k=0;
        for(int i=0;i<m;i++){
            int c=0;
            int l=0;
            int r=n-1;
            while(l<r){
                if(grid[i][l]!=grid[i][r]){
                    c++;
                }
                l++;
                r--;
            }
            k+=c;
        }
        int c=0;
        for (int i=0;i<n;i++) {
            int l=0;
            int r=m-1;
            while(l<r){
                if(grid[l][i]!=grid[r][i]) c++;
                l++;
                r--;
            }
        }
        return min(k,c);
    }
};