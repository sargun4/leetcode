//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    bool isvalid(int i, int j, int n, vector<vector<bool>>& vis) {
        return i >= 0 && i < n && j >= 0 && j < n && !vis[i][j];
    }
    
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int n) {
        int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
        int x1 = KnightPos[0] - 1, y1 = KnightPos[1] - 1;
        if (x1 == tx && y1 == ty) return 0;
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({x1, y1});
        vis[x1][y1] = true;
        
        int ans = 0;
        int xdir[8] = {1, 1, -1, -1, 2, -2, 2, -2};
        int ydir[8] = {2, -2, 2, -2, 1, 1, -1, -1};
        
        while (!q.empty()) {
            int size = q.size();
            ans++;
            
            while (size--) {
                pair<int, int> p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                for (int i = 0; i < 8; i++) {
                    int nrow = x + xdir[i];
                    int ncol = y + ydir[i];
                    
                    if (nrow == tx && ncol == ty) return ans;
                    
                    if (isvalid(nrow, ncol, n, vis)) {
                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        
        return ans;
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