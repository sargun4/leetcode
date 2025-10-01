class Solution {
public:
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    bool isPrime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    map<int,int> freqMap;
    void dfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&vis,int x,int p,int m,int n){
        vis[i][j]=1;
        x=x*10+mat[i][j];
        freqMap[x]++;
        int r=i+dirns[p][0];
        int c=j+dirns[p][1];
        if(isValid(r,c,m,n) && !vis[r][c]){
            dfs(r,c,mat,vis,x,p,m,n);
        }
        vis[i][j]=0;//backtrack
    }
    int mostFrequentPrime(vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int p=0;p<8;p++){
                    dfs(i,j,mat,vis,0,p,m,n);
                }
            }
        }
        int ans=-1;
        int maxi=0;
        for(auto it:freqMap){
            int num=it.first;
            int freq=it.second;
            if(num>10 && isPrime(num) && freq>=maxi){
                ans=num;
                maxi=freq;
            }
        }
        return ans;
    }
};