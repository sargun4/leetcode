//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    int atoi(string s) { 
        int num=0;
        int i=0;
        if(s[0]=='-')
        i++;
        while(i<s.length()){
            if(s[i]<'0' or s[i]>'9')
                return -1;
            num*=10;
            num+=(s[i]-'0');
            i++;
        }
        if(s[0]=='-')
            num*=-1;
        return num;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends