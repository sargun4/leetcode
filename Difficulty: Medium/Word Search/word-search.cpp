class Solution {
public:
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i,int j,int idx,vector<vector<char>>&mat,vector<vector<bool>>&vis,string&word,int n,int m){
        int wordlen=word.length();
        if(idx==wordlen){
            return true;
        }
        if(i>=n||i<0||j>=m || j<0 || vis[i][j] || mat[i][j]!=word[idx]){
            return false;
        }
        vis[i][j]=true;
        bool ans=false;
        for(auto&d:dirns){
            int nx=i+d[0];
            int ny=j+d[1];
            ans |= dfs(nx,ny,idx+1,mat,vis,word,n,m);
        }
        vis[i][j]=false;
        return ans;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n=mat.size();
        int m=mat[0].size();
        int start_ch=word[0];
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(start_ch==mat[i][j]){//start bfs frm here
                    if(dfs(i,j,0,mat,vis,word,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};