//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    set<string> st; // Set to store unique lcs'
    void helper_print(string s, string t, int i, int j, string &temp, vector<string> & ans, int ctr){
        if(ctr == 0){
            if(st.find(temp) == st.end()){ //if we dont find any other subseq=temp 
            // If the subsequence is unique
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        if(i >= s.size() || j >= t.size()) return;//If either condition is true, it means we have exhausted one of the input strings, 
        // and there are no more characters to compare 
        for(int row=i;row<s.size();row++){
            for(int col=j;col<t.size();col++){
                if(s[row] == t[col]){
                    temp.push_back(s[row]);
                    helper_print(s, t, row+1, col+1, temp, ans, ctr-1);
                    temp.pop_back(); //backtracking
                }
            }
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t){
        int n = s.size();
        int m = t.size();
        int dp[n+1][m+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<m+1;j++){
	            if(i == 0 || j == 0){
	                dp[i][j] = 0;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        } 
        int lcs_length = dp[n][m];  
        vector<string> ans;
        string temp = "";
        helper_print(s, t, 0, 0, temp, ans, lcs_length);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends