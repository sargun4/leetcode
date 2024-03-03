//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



#include <bits/stdc++.h> 
using namespace std; 
class Solution{
	public:
    vector<int> spiral(vector<vector<int>> &a,int n, int m){
        int sr=0;
        int sc=0;
        int er=n-1;
        int ec=m-1;
        vector<int> res;
        while(sr<=er && sc<=ec){
            for(int j=sc;j<=ec;j++){
                res.push_back(a[sr][j]);
            }
            sr++;
            for(int i=sr;i<=er;i++){
                res.push_back(a[i][ec]);
            }
            ec--;
            if(sr<=er){
                for(int j=ec;j>=sc;j--){
                    res.push_back(a[er][j]);
                }
                er--;
            }
            if(sc<=ec){
                for(int i=er;i>=sr;i--){
                    res.push_back(a[i][sc]);
                }
                sc++;
            }
        }
        return res;
    }
	int findK(vector<vector<int>> &a, int n, int m, int k){
        vector<int> res=spiral(a,n,m);
        int ans=res[k-1];
        return ans;
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
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends