class Solution {
public:
    unordered_map<int,int> ht;//ht of each node
    unordered_map<int,int> ans;//stores max ht after removing node
    
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        int lht=getHeight(root->left);
        int rht=getHeight(root->right);
        return ht[root->val]=1+max(lht,rht);
    }
    //dfs to compute max ht after removal
    void dfs(TreeNode* root, int depthAbove, int maxAbove) {
        if(!root) return;
        //max ht excluding curr node = max from above path
        ans[root->val] = maxAbove;
        
        //get children's hts
        int lht = root->left ? ht[root->left->val] : 0;
        int rht = root->right ? ht[root->right->val] : 0;
        
        // for left child, max above includes right child's ht
        if(root->left)
            dfs(root->left, depthAbove + 1, max(maxAbove, depthAbove + rht));
        
        // for right child, max above includes left child's ht
        if(root->right)
            dfs(root->right, depthAbove + 1, max(maxAbove, depthAbove + lht));
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        getHeight(root);//compute ht of each subtree
        dfs(root,0,0);//compute max ht after removal
        vector<int> res;
        for(int q:queries){
            res.push_back(ans[q]);
        }
        return res;
    }
};
