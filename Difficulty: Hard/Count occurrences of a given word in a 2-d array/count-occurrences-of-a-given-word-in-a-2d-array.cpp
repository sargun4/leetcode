class Solution {
public:
    int check(int i,int j,vector<vector<char>>&mat,string&target,int idx){
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        if(i>=m || j>=n || i<0|| j<0 || mat[i][j] != target[idx]){
            return 0;
        }
        if(idx==target.size()-1){//last cahr matched
            return 1;
        }
        // Store the current character and mark cell as visited
        char temp=mat[i][j];
        mat[i][j]='0';
        int ctr=0;
        int l=check(i,j+1,mat,target,idx+1);
        int d=check(i+1,j,mat,target,idx+1);
        int r=check(i,j-1,mat,target,idx+1);
        int u=check(i-1,j,mat,target,idx+1);
        ctr+=(l+d+r+u);
        mat[i][j]=temp;//backtrack-restore the cahr
        return ctr;
    }
    int findOccurrence(vector<vector<char> > &mat, string target) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=check(i,j,mat,target,0);
            }
        }
        return ans;
    }
};