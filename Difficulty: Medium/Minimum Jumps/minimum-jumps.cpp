//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(arr[0]==0 && n>1) return -1; //frist idx elmnt=0=>cant go any further
        if(n==1) return 0;
        int steps=arr[0];
        int maxreach=arr[0];
        int jumps=1;
        for(int i=1;i<n;i++){
            if(i==n-1) return jumps; //reached last idx
            if(steps>0){
            if(steps==0){
                if(i>=maxreach) return -1;
                jumps++;
                maxreach=max(maxreach,arr[i]+i);
                steps--;
            }
                steps=maxreach-i;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends