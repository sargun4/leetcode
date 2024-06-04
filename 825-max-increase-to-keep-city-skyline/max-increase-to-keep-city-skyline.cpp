class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=0;
        vector<int> maxrowvals(n,0);
        vector<int> maxcolvals(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxrowvals[i]=max(maxrowvals[i],grid[i][j]);
                maxcolvals[j]=max(maxcolvals[j],grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res+=min(maxrowvals[i],maxcolvals[j])-grid[i][j];
            }
        }
        return res;
    }
};