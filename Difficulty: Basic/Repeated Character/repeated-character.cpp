//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s){
        unordered_map<char,int> freqs;
        for(auto ch:s){
            freqs[ch]++;
        }
        char c='#';
         for(int i=0;i<s.length();i++){
            if(freqs[s[i]]>1) return s[i];
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends