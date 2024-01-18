//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n){
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++){
            if (gallery[i] == 1){
                continue;
            }
            int left=max(0,i-gallery[i]);
            int right=max(0,i+gallery[i]);
            v.push_back({left,right});
        }
        sort(begin(v),end(v));
        int top=0;
        int target=0;
        int i=0;
        while(target<n){
            int maxrightend=-1;
            while(i<v.size()){
                if(v[i].first<=target){
                    maxrightend=max(maxrightend,v[i].second);
                    i++;
                }else{
                    break;
                }
            }
            if(maxrightend<target){
                return -1;
            }
            top++;
            target=1+maxrightend;
        }
        return top;
    } 
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends