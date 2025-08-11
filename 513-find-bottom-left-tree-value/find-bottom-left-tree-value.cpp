class Solution {
public:
    int ht(TreeNode* root){
        if(root==NULL) return 0;
        int lht=ht(root->left);
        int rht=ht(root->right);
        return max(lht,rht)+1;
    }
    vector<vector<int>> lvlorder(TreeNode* root){
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> lvl;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node)
                    lvl.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        return res;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> res=lvlorder(root);
        return res.back()[0];
    }
};