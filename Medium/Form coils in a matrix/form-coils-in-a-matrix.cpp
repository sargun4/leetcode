//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h> 
using namespace std; 
class Solution{
	bool inBoard(int x, int y, int n){
        if(x>=n || y>=n || x<0 || y<0) return 0;
        return 1;
    }
public:
    vector<vector<int>> formCoils(int n) {
        n = 4*n;
        vector<vector<int>> V(n,vector<int> (n,-1));
        int ctr = 1;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++){
                V[i][j]=ctr;
                ctr++;
            }
      
        int XI = n/2 - 1;
        int YI = n/2;
        vector<int> ans1, ans2;
        vector<string> direction = {"down", "left", "up", "right"};
        int dir = 0;
        ans1.push_back(V[XI][YI]);
        int steps = 2;
        int incSteps = 0;
        while(V[XI][YI]!=1){
            for(int i = 0;i<steps;i++){
                if(V[XI][YI]==1) 
                    break;
                
                if(direction[dir]=="down")
                    XI++;
                else if(direction[dir]=="left") 
                    YI--;
                else if(direction[dir]=="up") 
                    XI--;
                else if(direction[dir]=="right") 
                    YI++;
                
                if(inBoard(XI, YI, V.size())) 
                    ans1.push_back(V[XI][YI]);
            }
            dir = (dir+1)%4;
            incSteps++;
            if((incSteps%2)==0)
                steps=steps + 2;
        }
        for(auto i:ans1)
            ans2.push_back(n*n+1 -i);
        V.clear();
        V.push_back(ans2);
        V.push_back(ans1);
        return V;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends