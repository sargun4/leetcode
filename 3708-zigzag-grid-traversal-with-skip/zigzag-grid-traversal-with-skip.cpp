class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m=grid.size();//no of rows
        int n=grid[0].size();
        vector<int> res;
        int flag=true;//to go right
        for(int i=0;i<m;i++){
            if(flag){//l to r
                for(int j=0;j<n;j+=2){
                    res.push_back(grid[i][j]);
                }
            }else{
                int start=n%2==0 ? n-1:n-2; // if row length is even, while going l to r first element is used, last is not used, then in next row it starts from last element
                for(int j=start;j>=0;j-=2){// r to l, skipping alt cells
                    res.push_back(grid[i][j]);
                }
            //while going l to r, it will always have the first element
            //since total element in a pair to l to r & r to l is even   
            }
            flag=!flag;//toggle dirn             
        }
        return res;
    }
};