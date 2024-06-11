   

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>lvl;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        vector<int> ans;
        int n=res.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<res[i].size();j++){
                ans.push_back(res[i][j]);
            }
        }
        int l=ans.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(ans[i]+ans[j]==k){
                    return true;
                }
            }
        }
        return false;
    }
};
       