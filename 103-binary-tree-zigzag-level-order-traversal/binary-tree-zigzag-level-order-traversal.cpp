class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                //find position to fill node's val
                int idx=(flag) ? i:(size-1-i); //if flag is true, store in row in normal order ; else store in rev order; 
                row[idx]=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            //after each lvl,zigzag
            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};