//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution{
public:
    bool allZero(vector<int> ctr){
        for (int &i : ctr) 
            if (i != 0)
                return false;
        return true;
    }
	int search(string pat, string txt) {
        int n=txt.size();
        int k=pat.length();
        vector<int> ctr(26,0);
        //count freq of each char in pat string
        for(int i=0;i<k;i++){
            char ch=pat[i];
            ctr[ch-'a']++;
        }
        int i=0,j=0;
        int res=0;
        //sliding window
        while(j<n){
            ctr[txt[j]-'a']--;
            if(j-i+1==k){
                if(allZero(ctr)){
                    res++;
                }
                ctr[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends