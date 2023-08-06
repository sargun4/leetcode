class Solution {
public:
    string getSubtreeStr(TreeNode* root,unordered_map<string,int> &mp,vector<TreeNode*>&res){
        if(root==NULL) return "N";
        string s=to_string(root->val)+","+getSubtreeStr(root->left,mp,res)+","+
        getSubtreeStr(root->right,mp,res);
        if(mp[s]==1){
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> res;
        getSubtreeStr(root,mp,res);
        return res;
    }
};