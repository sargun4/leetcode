//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

 
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
    public:
    void dfs(int x,int y, vector<vector<int>>& matrix, int N, int M){
        if(x<0 || y<0 || x>=N || y>=M || matrix[x][y]==0)
            return;
        matrix[x][y] = 0;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i],matrix,N,M);
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int ans = 0;   
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if((i==0 || j==0 || i==N-1 || j==M-1) && matrix[i][j]==1){
                    dfs(i,j,matrix,N,M);
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]==1){
                    dfs(i,j,matrix,N,M);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends