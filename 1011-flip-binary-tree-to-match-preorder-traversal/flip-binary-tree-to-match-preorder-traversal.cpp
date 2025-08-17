class Solution {
public:
    vector<int> ans;
    int idx=0;
    bool isFlippable=true;
    void dfs(TreeNode* root, vector<int>& voyage) {
        if(!root || !isFlippable){
            return;
        }

        //if curr node doesn't match voyage, impossible
        if (root->val != voyage[idx]) {
            isFlippable = false;
            return;
        }
        idx++;
     // If left child exists and doesn't match next voyage, we need to flip
        if (root->left && idx < voyage.size() && root->left->val != voyage[idx]) {
            ans.push_back(root->val);          // record flip
            swap(root->left, root->right);     // perform flip
        }

        if(root->left) dfs(root->left,voyage);
        if(root->right) dfs(root->right,voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root,voyage);
        if(!isFlippable) return {-1};
        return ans;
    }
};