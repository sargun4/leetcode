class Solution {
public:
    vector<vector<int>> dirns = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}};
    bool dfs(vector<vector<char>>&board,vector<string>&dict,int i,int j,string&word,int idx,int m,int n){
        if(i<0||j<0||i>=m||j>=n|| board[i][j]=='$'){
            return false;
        }
        // If we're at the last character, return true if it matches
        if(idx==word.size()-1){
            return board[i][j]==word[idx];//check if last char mathces
        }
        //if curr char doesnt match - false
        if(word[idx]!=board[i][j]){
            return false;
        }
        char og=board[i][j];
        board[i][j]='$';
        bool flag=false;
        for(auto&d:dirns){
            int nx=i+d[0];
            int ny=j+d[1];
            flag |= dfs(board,dict,nx,ny,word,idx+1,m,n);
        }
        board[i][j]=og;// Backtrack and unmark cell
        return flag;
    }
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        int m = board.size();
        int n = board[0].size();
        unordered_set<string> set;//avpid dupls
        vector<string> ans;
        for(auto&word:dictionary){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    // Start DFS only if first character matches
                    if(word[0]==board[i][j]){
                        if(dfs(board,dictionary,i,j,word,0,m,n)){
                            set.insert(word);
                        }
                    }
                }
            }
        }
        for(auto it:set){
            ans.push_back(it);
        }
        return ans;
    }
};

