//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, vector<int> &arr, vector<int> &ans, int sum) {
        // Base case: when all elements are considered
        if (i == -1) {
            ans.push_back(sum);
            return;
        }

        // Include the current element
        solve(i - 1, arr, ans, sum + arr[i]);

        // Exclude the current element
        solve(i - 1, arr, ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        solve(N - 1, arr, ans, 0);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends