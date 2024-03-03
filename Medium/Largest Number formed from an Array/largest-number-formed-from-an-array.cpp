//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
 
// / Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution{
    public:
    static bool cmp(string& s1,string& s2)
    {
        if((s1+s2)>(s2+s1))
        return 1;
        else
        return 0;
    }
	string printLargest(int n, vector<string> &arr) {
	    sort(arr.begin(),arr.end(),cmp);
	    string ans="";
	    for(auto& it:arr)
	    ans+=it;
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends