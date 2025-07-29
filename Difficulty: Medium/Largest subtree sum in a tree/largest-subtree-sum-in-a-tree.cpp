class Solution {
public:
    int solve(Node*root,unordered_map<Node*,int> &map){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left,map);
        int r=solve(root->right,map);
        map[root]=l+r+root->data;
        return map[root];
    }
    int findLargestSubtreeSum(Node* root) {
        unordered_map<Node*,int> map;//{node:subtreesum}
        solve(root,map);
        int ans=INT_MIN;
        for(auto it:map){
            int sum=it.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};
