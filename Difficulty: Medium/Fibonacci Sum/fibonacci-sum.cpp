//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long int fibSum(long long int N){
       if(N == 0 ||N==1){ 
           return N;
       }
       long long a = 0; //first number
       long long b = 1; // second no.
       long long c; //third no. jo a and b ki madat se nikalenge
       long long sum = 1;
       for(int i=2; i<=N; i++){
           c = (a % 1000000007) + (b % 1000000007);
           sum += c;
           a = b; //updating the values of a and b 
           b = c;
       }
       return sum % 1000000007; //we have to do modulo with the sum also 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends