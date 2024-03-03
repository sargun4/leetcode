//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    vector<int> spiral(int n, int m, vector<vector<int>>&a){
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        vector<int> res;
        while(top<=bottom && left<=right){
            for(int j=left;j<=right;j++){
                res.push_back(a[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.push_back(a[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    res.push_back(a[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(a[i][left]);
                }
                left++;
            }
        }
        return res;
    }
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int> res=spiral(R, C, a);
        // Reverse the array elements to get it
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends