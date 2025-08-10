class Solution {
public:
    // DFS: Counts all paths starting from 'root' with sum = target
    int count(TreeNode*root,long long target){
        if(!root) return 0;
        long long rem=target-root->val;// Remaining target after visiting this node
        if(rem==0){//curr node completes the path, but we still continue to find further paths
            return 1+count(root->left,rem)+count(root->right,rem);
        }else{//continue xeploring children
            return count(root->left,rem)+count(root->right,rem);
        }
    }
    // BFS: For every node, count the paths starting from that node
    int pathSum(TreeNode*root,int targetSum){
        int ctr=0;//counts total paths
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            sum=0;
            ctr+=count(node,(long long)targetSum);//count all paths starting at this node
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return  ctr;
    }
};

////dfs
// class Solution {
// public:
//     //to count paths
//     int helper(TreeNode*root,int targetSum,long int currSum,unordered_map<long int,int> pathcount){
//         if(root==NULL) return 0;
//         currSum+=root->val;//add curr node val to prefix sum
//       //count the no of paths ending at curr node that sum to target
//         int count=pathcount[currSum-targetSum];
//         pathcount[currSum]++;//include curr prefix sum in the map
//         //rec
//         count+=helper(root->left,targetSum,currSum,pathcount)+helper(root->right,targetSum,currSum,pathcount);
//         //backtrack- remove curr prefix sum (important for sibling paths)
//         pathcount[currSum]--; //backtracking
//         return count;
//     }
//     int pathSum(TreeNode *root,int targetSum){
//         unordered_map<long int,int> pathcount;
//         pathcount[0]=1;//base case: one path with sum = 0
//         return helper(root,targetSum,0,pathcount);
//     }
// };
