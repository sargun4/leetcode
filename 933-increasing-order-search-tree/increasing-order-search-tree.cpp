class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {        
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front();
                v.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        sort(v.begin(),v.end());
        TreeNode* ans = new TreeNode(-1);
        TreeNode* temp = ans;
        for(int i=0;i<v.size(); i++){
            temp->right = new TreeNode(v[i]);
            temp=temp->right;
        }
        return ans->right;
    }
};