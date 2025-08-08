class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        maxPathDown(root,maxsum);
        return maxsum;
    }
    int maxPathDown(TreeNode* node,int &maxsum){
        if(node==NULL) return 0;
        
        int l=max(0,maxPathDown(node->left,maxsum));
        int r=max(0,maxPathDown(node->right,maxsum));

        maxsum=max(maxsum,l+r+node->val);
        
        return max(l,r)+node->val;
    }
};