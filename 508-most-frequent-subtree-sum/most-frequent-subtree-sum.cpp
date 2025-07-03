//postorder trav to calc subtree sum
//for each node,subtree sum= own val+sum(lsubtree)+sum(rsubtree)
class Solution {
public:
    //to compute subtree sums postorder
    int dfs(TreeNode* root, unordered_map<int, int>& freq, int& maxfreq) {
        if (!root) return 0;
        int lsum = dfs(root->left, freq, maxfreq);
        int rsum = dfs(root->right, freq, maxfreq);        
        int currsum = root->val + lsum + rsum;

        freq[currsum]++;
        maxfreq=max(maxfreq,freq[currsum]);//track the highest frequency
        return currsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>freq;//{subtree_sum:count}
        int maxfreq=0;
        dfs(root,freq,maxfreq);
        //all sums that have the highest frequency
        vector<int> res;
        for (auto& [sum, count]:freq) {
            if (count == maxfreq) {
                res.push_back(sum);
            }
        }
        return res;
    }
};