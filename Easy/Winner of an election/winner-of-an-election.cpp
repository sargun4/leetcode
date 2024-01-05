//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n){
      unordered_map<string, int> map;
      for(int i=0;i<n;i++){
        map[arr[i]]++;
      }
      int maxvotes = -1;
      string res;
      for (auto x : map){
        if (x.second > maxvotes){
          maxvotes = x.second;
          res = x.first;
        }else if(x.second==maxvotes){
          res = min(res, x.first);
        }
      }
      return {res,to_string(maxvotes)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends