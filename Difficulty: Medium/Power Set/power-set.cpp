//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


 
#include<bits/stdc++.h>
using namespace std; 

class Solution{
public:
    vector<string> res;
    void solve(string &s,string &curr,int idx){
        if(idx>=s.length()){//base case
            if(curr!="") res.push_back(curr);
            return;
        }
        curr.push_back(s[idx]);
        solve(s,curr,idx+1);
        curr.pop_back();
        solve(s,curr,idx+1);
    }
    vector<string> AllPossibleStrings(string s){
        string curr="";
        solve(s,curr,0);
        sort(begin(res),end(res));
        return res;
    }
}; 


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends