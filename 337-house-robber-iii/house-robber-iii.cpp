//if we include a node, we cannot include its direct children.
// Choices at each node are:
//1. Include the curr node & skip its immediate children (move to its gr&children).
//2. Exclude the curr node & move to its children.
class Solution {
public:
    int rob(TreeNode* root) {
        //memo table- maps each node to the computed maximum sum starting at that node.
        unordered_map<TreeNode*,int> map;//{node:sum}
        return solve(root,map);
    }
    int solve(TreeNode* root,unordered_map<TreeNode* ,int>&map){
        if(!root) return 0;//if we reach NULL node-nothing to take
        //if we hv alr computed max sum for this node,get it frm map
        if(map.find(root)!=map.end()){//avoid recomputation
            return map[root];
        }
        //skip curr house,so take its immedite children
        int nottake=solve(root->left,map)+solve(root->right,map);
        int take=root->val;
        // if there is a left child, add the sum from left child's left and right children (grandchildren of curr node)
        if(root->left){
            take+=solve(root->left->left,map)+solve(root->left->right,map);
        }
        // if there is a right child, add the sum from left child's left and right children (grandchildren of curr node)
        if(root->right){
            take+=solve(root->right->left,map)+solve(root->right->right,map);
        }
        map[root]=max(take,nottake);
        return map[root];
    }
};