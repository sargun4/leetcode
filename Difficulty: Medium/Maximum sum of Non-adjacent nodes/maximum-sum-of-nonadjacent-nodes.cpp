// Choices at each node:
//1.Include the curr node n skip its children (move to its grandchildren).
//2.Exclude the curr node n move to its children.
class Solution {
  public:
    //return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        unordered_map<Node*,int> map;
        return solve(root,map);
    }
    int solve(Node*root,unordered_map<Node*,int>&map){
        if(root==NULL) return 0;
        if(map.find(root)!=map.end()){//root alr exists in map
            return map[root];
        }
        int nottake=solve(root->left,map)+solve(root->right,map);
        int take=root->data;
        if(root->left){//skip this node and call rec on left n right child
            take+=solve(root->left->left,map);
            take+=solve(root->left->right,map);
        }
        if(root->right){
            take+=solve(root->right->left,map);
            take+=solve(root->right->right,map);
        }
        return map[root]=max(take,nottake);
    }
};