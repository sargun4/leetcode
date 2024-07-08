//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
vector<int> revEachRow(vector<int> &arr){
    stack<int> st;
    int n=arr.size();
    for(int i=0;i<n;i++){
        st.push(arr[i]);
    }
    arr.clear();
    for(int i=0;i<n;i++){
        int elmnt=st.top();
        st.pop();
        arr.push_back(elmnt);
    }
    return arr;
}
void rotate(vector<vector<int> >& matrix){
    int n=matrix.size();
    //foirst rev each row;
    for(int i=0;i<n;i++){
        matrix[i] = revEachRow(matrix[i]);
    }
    // then transpose;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends