//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int isRepresentingBST(int arr[], int N) {
        vector<int> a(arr, arr + N);  // Convert array to vector
        // Sort the vector
        sort(a.begin(), a.end());
        // Check if the original array and sorted vector are equal
        return (equal(arr, arr + N, a.begin()) ? 1 : 0);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.isRepresentingBST(arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends