//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size){
        unordered_map<int,int> freq;
        for(int i=0;i<size;i++){
            freq[a[i]]++;
        }
        int ans=-1;
        for(auto ch:freq){
            int el=ch.first;
            int ctr=ch.second;
            if(ctr>size/2){
                ans=el;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends