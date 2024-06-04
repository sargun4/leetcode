//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// 1. Loop backward through the string s :
//   - Start from the end and look for the first '0'.
// 2. Change the first '0' to '1':
//   - When found, change this '0' to '1'.
//   - Change all bits to the right to '0'.
// 3. Return the resulting string:
//   - Return the modified string starting from the first '1'.
// 4.  Handle all '1's case:
//   - If no '0' is found, prepend '1' to the string.

//  Example:
// - For  s = "1100" , the result is "1101".
// - For  s = "1111" , the result is "10000".


// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    string binaryNextNumber(string s) {
        for(int i=s.length();i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                for(int j=0;j<s.length();j++){
                    if(s[j]=='1')
                    return s.substr(j);
                }
            }
            s[i]='0';
        }
        return ('1'+s);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends