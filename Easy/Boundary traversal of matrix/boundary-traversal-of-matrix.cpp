//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
 
class Solution{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m) {
        vector<int>ans;
           int left=0;
           int right = m-1;
           int top=0;
           int bottom = n-1;
           for(int i=left;i<=right;i++){
               ans.push_back(matrix[top][i]);
           }
           top++;
           for(int i=top;i<=bottom;i++) {
               ans.push_back(matrix[i][right]);
           }
           right--;
           if(top<=bottom) {
           for(int i=right;i>=left;i--) {
               ans.push_back(matrix[bottom][i]);
           }
         }
           bottom--;
           if(left<=right) {
           for(int i=bottom;i>=top;i--) {
               ans.push_back(matrix[i][left]);
           }
          }
           left++;
       return ans;
    }
};

 


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends