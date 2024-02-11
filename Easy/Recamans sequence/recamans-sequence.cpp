//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> recamanSequence(int n) {
        if (n < 2) {
            // For n=0 or n=1, the sequence is just [0] or [0, 1] respectively.
            return vector<int>(n);
        }

        unordered_set<int> visited{0, 1};
        vector<int> sequence{0, 1};
        int current = 1;

        for (int i = 2; i <= n; ++i) {
            current = (current - i >= 0 && visited.find(current - i) == visited.end()) ? 
                      (current - i) : (current + i);
            visited.insert(current);
            sequence.push_back(current);
        }

        return sequence;
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
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends