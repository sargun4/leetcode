//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n){   
        map<int,int> mp; 
        int ans = 0;
        for(int i=1; i<a.size(); i++){
            a[i]+=a[i-1];
        }
        for(int i=0; i<a.size(); i++){
            if(a[i] == 0) ans = i+1;
            else if(mp.find(a[i])!=mp.end()){
                ans = max(ans, i-mp[a[i]]);
            }
            else mp[a[i]] = i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends