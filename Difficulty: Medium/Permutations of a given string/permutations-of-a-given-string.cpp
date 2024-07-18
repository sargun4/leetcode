//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
    	void solve(set<string> &perms,int idx,string &s){
    	    int n=s.size();
    	    if(idx>=n){
    	        perms.insert(s);
    	        return;
    	    }
    	    for(int i=idx;i<n;i++){
    	        if(i>idx && s[i]==s[i-1]) continue;
    	        swap(s[i],s[idx]);
    	        solve(perms,idx+1,s);
    	        swap(s[i],s[idx]);
    	    }
    	}
		vector<string>find_permutation(string s){
		    set<string> perms;
		    vector<string> res;
		    solve(perms,0,s);
		    
		    res.assign(perms.begin(),perms.end());
		    sort(res.begin(),res.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends