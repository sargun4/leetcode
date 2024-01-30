//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) {
    	if (x == 0 || x == 1)
    		return x;
        long long int start=1;
        long long int end=x/2;
        long long int ans;
        while(start<=end){
            long long int mid=(start+end)/2;
            long long int sqrt=mid*mid;
            if(sqrt==x){
                return mid;
            }
            if(sqrt<=x){
                start=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends