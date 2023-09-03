//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
    vector<int> dx={1,-1,1,-1,2,-2,2,-2};
    vector<int> dy={2,-2,-2,2,1,-1,-1,1};
    bool isvalid(int N,int x,int y){
        if(x>=0 && x<N && y>=0 && y<N) return true;
        return false;
    }
	double findProb(int N,int start_x, int start_y, int steps){
	    double dp[N][N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j][0]=1;
            }
        }
        for(int s=1;s<=steps;s++){
            for(int x=0;x<N;x++){
                for(int y=0;y<N;y++){
                    double prob=0;
                    for(int i=0;i<8;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(isvalid(N,nx,ny)){
                            prob+=dp[nx][ny][s-1]/(8.0);
                        }
                    }
                    dp[x][y][s]=prob;
                }
            }
        }
        return dp[start_x][start_y][steps];
	}
};

//#include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int N;
//     unordered_map<string,double> map;
//     vector<pair<int,int>> dirn={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
//     double solve(int r,int c,int k){
//         if(r<0||r>=N||c<0||c>=N){ //out of bounds
//             return 0;
//         }
//         if(k==0){//0 steps
//             return 1;
//         }
//         string key=to_string(k)+"_"+to_string(r)+"_"+to_string(c);
//         if(map.find(key)!=map.end()){
//             return map[key];
//         }

//         double ans=0;
//         for(auto &dir:dirn){
//             int nrow=r+dir.first;
//             int ncol=c+dir.second;
//             ans+=(double)solve(nrow,ncol,k-1);
//         }
//         return map[key]=(double)ans/(8.0);
//     }
//     double knightProbability(int n, int k, int row, int column) {
//         N=n;
//         return solve(row,column,k);
//     }
// };





//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends