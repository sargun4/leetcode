//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <bits/stdc++.h>
using namespace std;   
// Time Complexity: O(N^3)
// Auxiliary Space: O(N^2)
class Solution {
public:
    int dp[101][101]; // Memoization table to store computed results  
    // Recursive function to calculate the minimum cost of matrix multiplication
    int solve(int arr[], int i, int j) {
        // Base case: If the matrix has only one element or is empty, cost is 0
        if (i >= j) {
            return 0;
        } 
        // Check if the result for this subproblem is already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        } 
        int minCost = INT_MAX; 
        // Iterate through all possible ways to split the matrices and find the minimum cost
        for (int k = i; k < j; k++) {
            int cost = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]); 
            // Update minimum cost if the current configuration is more optimal
            if (cost < minCost) {
                minCost = cost;
            }
        } 
        // Memoize the result and return the minimum cost
        return dp[i][j] = minCost;
    } 
    // Function to initiate the matrix multiplication and return the minimum cost
    int matrixMultiplication(int N, int arr[]) {
        // Initialize the memoization table with -1
        memset(dp, -1, sizeof(dp)); 
        // Call the recursive function to compute the minimum cost
        return solve(arr, 1, N - 1);
    }
};
 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends