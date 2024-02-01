//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool checkPangram (string &S) {
       if(S.size()<26)
           return 0;
       int arr[26]={0};
        for(int i=0;i<S.size();i++){
            if(S[i]>='a'&& S[i]<='z')
                arr[S[i]-'a']++;
            
            if(S[i]>='A'&& S[i]<='Z')
                arr[S[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]<=0){
                return 0;
            }
        }
        return 1;
   }
};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends