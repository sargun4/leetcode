//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   int kLevelSum(int K, string S) { 
       int level = -1 ;
       int sum = 0 ;
       for( int i = 0 ; i< S.size() ; i++)
       {
           if(S[i]=='(')
           {
               level++ ;
           }
           else if(S[i] == ')')
           {
               level-- ;
           }
           else 
           {
          
            if(level==K){
                string st = "";
                st=st+S[i];
                while(S[i+1] != '('){
                    i++;
                    st=st+S[i];
                }
                sum=sum + stoi(st);
            }
           }
       }
       
       return sum ;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>K;
        cin>>S;

        Solution ob;
        cout << ob.kLevelSum(K,S) << endl;
    }
    return 0;
}
// } Driver Code Ends