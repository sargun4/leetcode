//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
class Solution{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix){
        int row=matrix.size();
        int col=matrix[0].size();
        bool arr_row[row];
        bool arr_col[col];
        
        fill(arr_row,arr_row+row,false);
        fill(arr_col,arr_col+col,false);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    arr_row[i] = true;
                    arr_col[j] = true;
                }
            }
        }
        for (int i = 0; i < row; i++){
            if(arr_row[i]==1){
                for (int j = 0; j < col; j++){
                    matrix[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < col; i++){
            if(arr_col[i]==1){
                for (int j = 0; j < row; j++){
                    matrix[j][i] = 1;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends