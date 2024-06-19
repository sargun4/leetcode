class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        int ans=root->val;
        while(!q.empty()){
            int n=q.size();
             int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                node->val=ans-(node->val);
                if(node->left){ 
                    q.push(node->left);
                    sum+=node->left->val;
                }
                if(node->right) {
                    q.push(node->right);
                    sum+=node->right->val;
                }
                if(node->left && node->right){
                    int x=node->right->val+node->left->val;
                    node->left->val=x;
                    node->right->val=x;
                }
            }
            ans=sum;
        }
        return root;
    }
};