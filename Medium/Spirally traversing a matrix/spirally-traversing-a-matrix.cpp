//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c){
        vector<int> l;
        int top=0;
        int bottom=r-1;
        int left=0;
        int right=c-1;
        while(top<=bottom && left<=right){
            for(int j=left;j<=right;j++){
                l.push_back(matrix[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                l.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    l.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    l.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return l;
    }
};

// class Solution: 
//     def spirallyTraverse(self,matrix, r, c):  
//         lst=[]
//         left,right,top,bottom=0,c-1,0,r-1
//         while left<=right and top<=bottom:
//             for i in range(left,right+1):
//                 lst.append(matrix[top][i])
//             top+=1
//             for i in range(top,bottom+1):
//                 lst.append(matrix[i][right])
//             right-=1
//             if top<=bottom:
//                 for i in range(right,left-1,-1):
//                     lst.append(matrix[bottom][i])
//                 bottom-=1
//             if left<=right:
//                 for i in range(bottom,top-1,-1):
//                     lst.append(matrix[i][left])
//                 left+=1 
//         return(lst)

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends