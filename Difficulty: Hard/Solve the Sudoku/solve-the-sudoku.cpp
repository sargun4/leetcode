//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  { 
        int n=N;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    for(char c=1;c<=9;c++){
                        if(isvalid(grid,i,j,c)){
                            grid[i][j]=c;
                            if(SolveSudoku(grid)==true) return true;
                            else grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(int grid[N][N],int row,int col,char c){
        for(int i=0;i<9;i++){
            if(grid[i][col]==c) return false;
            if(grid[row][i]==c) return false;
            if(grid[3*(row/3)+i/3][3*(col/3)+(i%3)]==c) return false; //insid 9x9gbox
        }
        return true;
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                std::cout<< grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends