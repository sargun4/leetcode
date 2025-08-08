class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++){//start frm 2nd row
            for(int j=0;j<=i;j++){
                if(j==0){
                    int up=triangle[i-1][j]; //direct above elmnt
                    //1st elmnt in next row- can only come frm direct above
                    triangle[i][j] += up;
                }else if(j==i){
                    int upLeft=triangle[i-1][j-1]; //diag above on left
                    //last elmnt  in next row- can only come frm upLeft;
                    triangle[i][j] += upLeft;
                }else{
                    int up=triangle[i-1][j]; //direct above elmnt
                    int upLeft=triangle[i-1][j-1]; //diag above on left
                    //any elmnt in middle
                    triangle[i][j] += min(up,upLeft);
                }
            }
        }
        //ans is min in last row
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};