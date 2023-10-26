class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> lvl;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};

// vector<vector<int>> levelOrder1(TreeNode* root) {
// 		vector<vector<int>> res;
// 		if (!root)
// 			return res;
// 		queue<TreeNode*> level_node;
// 		level_node.push(root);
// 		while (!level_node.empty()) {
// 			vector<int> level_val;
// 			auto sz = level_node.size();
// 			for (decltype(sz) i = 0; i < sz; ++i) {
// 				TreeNode *node = level_node.front();
// 				level_node.pop();
// 				level_val.push_back(node->val);
// 				if (node->left)
// 					level_node.push(node->left);
// 				if (node->right)
// 					level_node.push(node->right);
// 			}
// 			res.push_back(level_val);
// 		}
// 		return res;
// 	}