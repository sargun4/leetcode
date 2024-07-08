//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S){
    unordered_map<char, int> m;
    // Count the frequency of each character in the string
    for (char c : S) {
        m[c]++;
    }
    int oddCount = 0;
    
    // Count how many characters have an odd frequency
    for (const auto& pair : m) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }
    if (oddCount > 1) {
        return 0; // More than one odd frequency means it can't form a palindrome
    }
    
    return 1; // It's possible to rearrange into a palindrome
}