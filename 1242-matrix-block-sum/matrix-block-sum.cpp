class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int i,j,m = mat.size(),n = mat[0].size();
        for(i = 0; i < m ;i++){
            for(j = 0; j < n; j++){
                if(i==0&&j==0)continue;
                else if(i==0){
                    mat[i][j] += mat[i][j-1];
                }else if(j==0){
                    mat[i][j] += mat[i-1][j];
                }else{
                    mat[i][j] += mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
                }
            }
        }
        int a,b,c,d;
        vector<vector<int>> ans(m,vector<int> (n));
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                a = max(i-k,0);
                b = max(0,j-k);
                c = min(i+k,m-1);
                d = min(j+k,n-1);
                if(a==0&&b==0){
                    ans[i][j] = mat[c][d];
                }else if(a==0){
                    ans[i][j] = mat[c][d]-mat[c][b-1];
                }else if(b==0){
                    ans[i][j] = mat[c][d]-mat[a-1][d];
                }else{
                    ans[i][j] = mat[c][d]+mat[a-1][b-1]-mat[a-1][d]-mat[c][b-1];
                }
            }
        }
        return ans;
    }
};