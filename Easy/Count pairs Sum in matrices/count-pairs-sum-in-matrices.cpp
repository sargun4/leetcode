//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

 
#include <bits/stdc++.h>
using namespace std;
 
class Solution{
public:	
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x){
        int i1 = 0;
        int j1 = 0 ;
        int i2 = n - 1; 
        int j2 = n - 1 ;
        int ctr= 0 ;
        while(i1<n && j1<n && i2>=0 && j2>=0 ){
            int sum = mat1[i1][j1] + mat2[i2][j2];
            if(sum<x){
                j1++;
                if(j1==n){
                    i1++;
                    j1=0;
                }
            }
            else if(sum>x){
                j2--;
                if(j2<0){
                    j2=n-1;
                    i2--;
                }
            }
           else{
                ctr++;
                j1++;
                if(j1==n){
                    j1=0;
                    i1++;
                }
               j2--;
               if(j2<0){
                    j2=n-1;
                    j2--;
                }
           }
             
        }
        return ctr;
    }
}; 

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends