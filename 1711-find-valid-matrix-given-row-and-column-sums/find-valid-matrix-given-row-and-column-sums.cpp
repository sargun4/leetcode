class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        int i=0;
        int j=0;
        while(i<m && j<n){
            mat[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=mat[i][j];
            colSum[j]-=mat[i][j];
            if(rowSum[i]==0){
                i++;
            }
            if(colSum[j]==0){
                j++;
            }
        }
        return mat;
    }
};