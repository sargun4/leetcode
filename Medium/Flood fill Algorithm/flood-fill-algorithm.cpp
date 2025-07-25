//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


 
#include<bits/stdc++.h>
using namespace std;
//T-O(n*m)
//S-O(n*m)
class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newcolor,int drow[],int dcol[],int initialcolor){
        ans[row][col]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && image[nrow][ncol]==initialcolor
            && ans[nrow][ncol]!=newcolor){
                dfs(nrow,ncol,ans,image,newcolor,drow,dcol,initialcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialcolor=image[sr][sc];
        vector<vector<int>> ans=image;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        dfs(sr,sc,ans,image,newColor,delrow,delcol,initialcolor);
        return ans;
    }
};  

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends