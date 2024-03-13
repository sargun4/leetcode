//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


 #include<bits/stdc++.h>
using namespace std;
 
class Solution{
public:
    void solve(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j){
        int n=grid.size();
        if(i<0||i>=n||j<0||j>=n||vis[i][j]==true||grid[i][j]==0){//if out of bounds or already vis or wall
            return;
        } 
        vis[i][j]=true;
        solve(grid,vis,i+1,j);
        solve(grid,vis,i-1,j);
        solve(grid,vis,i,j+1);
        solve(grid,vis,i,j-1);
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sr,sc,er,ec;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){//starting cell
                    sr=i;
                    sc=j;
                }if(grid[i][j]==2){//dest
                    er=i;
                    ec=j;
                }
            }
        }
        solve(grid,vis,sr,sc);
        return vis[er][ec];
    }
};  

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends