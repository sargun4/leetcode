class Solution {
public:
    vector<vector<int>> dirns{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1},
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum_neighbours=0;
                int count_neighbours=0;
                for(auto &it:dirns){
                    int x = i+it[0];
                    int y = j+it[1];
                    if(x>=0 && x<m && y>=0 && y<n){ //in bounds
                        sum_neighbours+=img[x][y];
                        count_neighbours++;
                    }
                }
                res[i][j]=sum_neighbours/count_neighbours;
            }
        }
        return res;
    }
};