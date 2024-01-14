//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



// https://www.geeksforgeeks.org/problems/search-pattern0205/1
#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(|txt|).
// Auxiliary Space: O(|txt|).
class Solution{
public:
    void computeLPS(string pat,vector<int> &lps,int m){
        int len = 0;//LEN OF PREV longest prefix n suffix which were equal
        lps[0] = 0;//lps[0] is always 0
        int i=1;
        while(i<m){
            if (pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string pat, string txt){
        int n=txt.length();
        int m=pat.length();
        vector<int> res;
        //create an lps arr to store the len of longest proper prefix which is also a suffix
        //lps[i]= the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]
        vector<int> lps(m,0);
        computeLPS(pat,lps,m);
        //apply kmp 
        int i=0;
        int j=0;
        while (i<n){
            if(txt[i]==pat[j]){
                i++; j++;
            }
            if(j==m){
                //we have found pattern match
                res.push_back(i-m+1);//starting index of matched pattern in text=(i-m+1)
                j=lps[j-1];//go to next possible matching char in pat
            }else if(txt[i]!=pat[j]){
                //If there is a mismatch, then goto the next possible starting point from where we
                // can still try for matches 
                if(j!=0)// If not at beginning, then go to the next possible character in text[] 
                    j=lps[j-1];
                else// If at begining and no match so far, then increase i value 
                    i++; 
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends