//each node in a FBT has either 0 or 2 children. since there is a root node, a FBT will always have an odd no of nodes (root node + even child nodes)
class Solution {
public:
    unordered_map<int,vector<TreeNode*>> dp;//memo table
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0){//cant form a FBT w even no of nodes
            return {};
        }
        if(n==1){
            return {new TreeNode()};
        }
        if(dp.find(n)!=dp.end()){//n alr in table
            return dp[n];
        }
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
// we can use one node as the root node and split the other n - 1 nodes between the left and right subtrees in all possible ways.So, if we place i nodes in the left subtree and n - i - 1 in the right subtree
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(n-i-1);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(0,l,r);
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }
};