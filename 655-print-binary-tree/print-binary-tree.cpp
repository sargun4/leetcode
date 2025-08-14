//bfs
class Solution {
public:
    int ht(TreeNode* root){
        if(!root) return 0;
        int lht=ht(root->left);
        int rht=ht(root->right);
        return 1+max(lht,rht);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int lvls=ht(root)-1;// total number of levels
        int rows=lvls+1;
        int cols=pow(2,rows)-1;
        vector<vector<string>> ans(rows,vector<string>(cols,""));
        unordered_map<TreeNode*,pair<int,int>> map;//{node:{row,col}}
        queue<TreeNode*>q;
        q.push(root);
        // root position is always middle of the first row
        string rootStr=to_string(root->val);
        ans[0][(cols-1)/2]=rootStr;
        map[root]={0,(cols-1)/2};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                int row=map[node].first;
                int col=map[node].second;
                if(node->left){
                    q.push(node->left);
                    string rootLeft=to_string(node->left->val);
                    int row_lchild=row+1;
                    int col_lchild=col-pow(2,lvls-row-1);
                    //lchild at- ans[r+1][c-2^(height-r-1)]
                    ans[row_lchild][col_lchild]=rootLeft;
                    map[node->left]={row_lchild,col_lchild};
                }

                if(node->right){
                    q.push(node->right);
                    string rootRight=to_string(node->right->val);
                    int row_rchild=row+1;
                    int col_rchild=col+pow(2,lvls-row-1);
                    //rchild at- ans[r+1][c+2^(height-r-1)]
                    ans[row_rchild][col_rchild]=rootRight;
                    map[node->right]={row_rchild,col_rchild};
                }
            }
        }
        return ans;
    }
};