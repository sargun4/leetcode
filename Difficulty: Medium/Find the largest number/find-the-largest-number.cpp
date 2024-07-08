//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool check(int n){
        string s=to_string(n);
        for(int i=1;i<s.size();i++){
            if(s[i-1]>s[i]){
                return false;
            }
        }
        return true;
    }
    int find(int N){
        for(int i=N;;i--){
            if(check(i)) return i;
        }
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
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends