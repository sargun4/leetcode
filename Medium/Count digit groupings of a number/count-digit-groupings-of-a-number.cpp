//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int n;
    int dp[101][1001];
    int solve(int i,int prevgrpsum,string &str){
        if(i>=n) return 1;
        if(dp[i][prevgrpsum]!=-1) 
        return dp[i][prevgrpsum];
        int currsum = 0;
        int res=0;
        for (int j=i ;j<n ;j++){
            currsum += str[j]-'0';

            if(currsum>=prevgrpsum){
                res+=solve(j+1,currsum,str);
            }
        }
        return dp[i][prevgrpsum]=res;
    }
	int TotalCount(string str){
        memset(dp,-1,sizeof(dp));
        n=str.length();
        return solve(0,0,str);

	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends