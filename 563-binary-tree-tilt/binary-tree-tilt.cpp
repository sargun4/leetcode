 

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode *root) {
		//Checking if there are some child tree and if its true, dfs it or else the node is leaf node therfore make it 0
        int left = (root->left ? dfs(root->left) : 0);
        int right = (root->right ? dfs(root->right) : 0);
		ans += abs(left - right);//titl
        return left + right + root->val;//returning the total sum
    }
    int findTilt(TreeNode* root) {
        if (root) dfs(root);
        return ans;
    }
};