class Solution {
public:
    //to count paths
    int helper(TreeNode*root,int targetSum,long int currSum,unordered_map<long int,int> pathcount){
        if(root==NULL) return 0;
        currSum+=root->val;//add curr node val to prefix sum
      //count the no of paths ending at curr node that sum to target
        int count=pathcount[currSum-targetSum];
        pathcount[currSum]++;//include curr prefix sum in the map
        //rec
        count+=helper(root->left,targetSum,currSum,pathcount)+helper(root->right,targetSum,currSum,pathcount);
        //backtrack- remove curr prefix sum (important for sibling paths)
        pathcount[currSum]--; //backtracking
        return count;
    }
    int pathSum(TreeNode *root,int targetSum){
        unordered_map<long int,int> pathcount;
        pathcount[0]=1;//base case: one path with sum = 0
        return helper(root,targetSum,0,pathcount);
    }
};
