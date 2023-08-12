class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //bfs
        queue<TreeNode*> q;
        q.push(root);
        bool past=false;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL)past=true;
            else{
                if(past==true){
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};