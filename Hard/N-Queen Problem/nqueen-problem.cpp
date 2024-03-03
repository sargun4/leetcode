//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    int N;
    bool isvalid(vector<string> &board,int row,int col){
        for(int i=row-1;i>=0;i--){//check up
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //check left diag up
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){//check up
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //check right diag up
        for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++){//check up
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
     void solve(vector<string> &board, int row) {
        if (row >= N) {
            // Convert the string board to a vector of integers representing column positions
            vector<int> solution;
            for (const auto &rowStr : board) {
                for (int col = 0; col < N; col++) {
                    if (rowStr[col] == 'Q') {
                        solution.push_back(col + 1); // Add 1 to make it 1-indexed
                        break;
                    }
                }
            }
            res.push_back(solution);
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isvalid(board, row, col)) {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(board, 0);

        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends