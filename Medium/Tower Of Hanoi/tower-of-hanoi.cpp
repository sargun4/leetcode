//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


 
#include <bits/stdc++.h> 
using namespace std;
 
class Solution{
    public:
    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        if(N==0) return 0;
        if(N==1){
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        int ctr=toh(N-1, from, aux, to);

        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        ctr++;

        ctr+=toh(N-1,aux,to,from);

        return ctr;
    } 
};
 
  

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends