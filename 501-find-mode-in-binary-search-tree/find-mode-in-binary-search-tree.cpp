class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            freq[node->val]++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        int maxfreq=0;
        for(auto&[key,val]:freq){
            maxfreq=max(maxfreq,val);
        }
        vector<int> ans;
        for(auto&[key,val]:freq){
            if(val==maxfreq){
                ans.push_back(key);
            }
        }
        return ans;
    }
};