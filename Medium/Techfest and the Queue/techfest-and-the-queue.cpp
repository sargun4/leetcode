//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int getPts(int x){
        int pts=0;
        for(int i=2;i<=sqrt(x);i++){
            while(x%i==0){
                pts++;
                x=x/i;
            }
        }
        if(x!=1){//eg=11,13,17
            pts++;
        }
        return pts;
    }
	int sumOfPowers(int a, int b){
	    int res=0;
        while(a<=b){
            res+=getPts(a);
            a++;
        }
        return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends