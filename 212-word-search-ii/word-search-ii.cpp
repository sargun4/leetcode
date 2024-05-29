// trie-212. Word Search II
class Solution {
public:
    vector<string> res;
    int m,n;
    //node struct for trie
    struct trieNode{
        bool endofword;
        string word;
        trieNode*children[26];
    };
    trieNode*getnode(){
        trieNode* node=new trieNode();
        node->endofword = false;
        node->word = "";
        for(int i=0; i<26; i++){
            node->children[i] =NULL;
        }
        return node;
    }
    void insert(trieNode*root,string &word){
        trieNode* mover = root; //mover node moves in the trie
        for(int i=0; i<word.length(); i++){
            char ch=word[i];
            if(mover->children[ch-'a']==NULL){
                mover->children[ch-'a'] =getnode();
            }
            mover=mover->children[ch-'a'];
        }
        mover->endofword=true;
        mover->word=word;
    }
    vector<vector<int>> dirns{{1,0},{-1,0},{0,1},{0,-1}};
    void findtriewords(vector<vector<char>>& board,int i,int j,trieNode* root){
        if(i<0||j<0||i>=m||j>=n) return ;
        if(board[i][j]=='$' || root->children[board[i][j]-'a']==NULL)
            return ; //if alreedy vis or the child on board isnt in trie
        root=root->children[board[i][j]-'a'];
        if(root->endofword==true){
            res.push_back(root->word);
            root->endofword=false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        //l,u,r,d
        for(vector<int>&dir:dirns){
            int nr=i+dir[0];
            int nc=j+dir[1];
            findtriewords(board,nr,nc,root);
        }
        board[i][j]=temp;//marking unvis now;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        trieNode* root=getnode();//crate
        //inser words in trie
        for(string & word : words){
            insert(root,word);
        }

        //travers board and find words in trie
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findtriewords(board,i,j,root);
                }
            }
        }
        return res;
    }
};