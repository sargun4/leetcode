//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i=0; int j=0; int previ=0; int prevj=0; int dirn=0;
        while(i<n and i>=0 and j<m and j>=0){
            previ=i;
            prevj=j;
            if(matrix[i][j]==1){//if equal to 1, then go to dirn to right of that cell
                matrix[i][j]=0;
                if(dirn==0){
                    i++;
                    dirn=1;
                }else if(dirn==1){
                    j--;
                    dirn=2;
                }else if(dirn==2){
                    i--;
                    dirn=3;
                }else if(dirn==3){
                    j++;
                    dirn=0;
                }
            }else{//if 0, no dirn change req
                if(dirn==0){
                    j++;
                }else if(dirn==1){
                    i++;
                }else if(dirn==2){
                    j--;
                }else if(dirn==3){
                    i--;
                }
            }
        }
        return {previ, prevj};
    }
};
 

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends