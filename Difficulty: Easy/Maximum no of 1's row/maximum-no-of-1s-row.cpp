//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        int maxOnes (vector <vector <int>> &mat, int n, int m){
            int max=INT_MIN;
            int ans;
            int count=0;
            for(int i=0;i<n;i++){
                 count=0;
                 for(int j=0;j<m;j++){
                     if(mat[i][j]==1){
                         count++;
                     }
                 }
                 if(count>max){
                     max=count;
                     ans=i;
                 }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends