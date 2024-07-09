//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends



// Sort the array in ascending order.
// Traverse the array from start to end.
// For every index i, create two variables l = i + 1 and r = n – 1 and run a loop until l is less than r.
// Check if the sum of arr[i], arr[l], and arr[r] is equal to zero. If it is, then return true as we have found a triplet.
// If the sum is less than zero, then increment the value of l by 1. By increasing the value of l, the sum will increase as the array is sorted, so arr[l+1] > arr[l].
// If the sum is greater than zero, then decrement the value of r. By decreasing the value of r, the sum will decrease as the array is sorted, so arr[r-1] < arr[r].
// In the end, if a triplet is not found, then return false.
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n){ 
        bool found=false;
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++){
            int l=i+1;
            int r=n-1;
            int x=arr[i];
            while(l<r){
                if(x+arr[l]+arr[r]==0){
                    l++;
                    r--;
                    found=true;
                    break;
                }else if(x+arr[l]+arr[r]<0){
                    l++;
                }else{
                    r--;
                }
            }
            if(found) break;
        }
        return found;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends