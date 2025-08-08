class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        int n=rowIndex+1;
        for(int i=0;i<n;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=triangle[i-1][j]+triangle[i-1][j-1]; //prevrows elmnt [i-1][j] + the one on its left [i-1][j-1]
            }
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};