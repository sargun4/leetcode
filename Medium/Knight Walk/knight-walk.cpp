//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int er=TargetPos[0];
        int ec=TargetPos[1];
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
	    int sr=KnightPos[0];
	    int sc=KnightPos[1];
        if(sr==er && sc==ec)
            return 0;
        int steps=0;
	    q.push({steps,{sr-1,sc-1}});
        vis[sr-1][sc-1]=1;
        int dx[8]={2,2,-2,-2,1,1,-1,-1};
        int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
        while(!q.empty()){
            auto it=q.front();
            int steps=it.first;
            int i=it.second.first;
            int j=it.second.second;
            q.pop();
            if(i==er-1 && j==ec-1){
                return steps;
            }
            for(int k=0;k<8;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && ny>=0 && nx<N && ny<N && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({steps+1,{nx,ny}});
                }
            }
            steps++;
        }
        return -1;
	}
}; 

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends