//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

 
class Solution{
    public: 
    vector<int> spiral(int a[MAX][MAX],int n,int m){
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        vector<int> res;
        while(top<=bottom && left<=right){
            for(int j=left; j<=right; j++){
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
    int findK(int a[MAX][MAX],int n,int m,int k){
 		vector<int> res=spiral(a,n,m);
        return res[k-1];
    }
};

 


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends