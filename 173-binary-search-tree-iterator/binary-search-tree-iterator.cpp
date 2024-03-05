// https://leetcode.com/problems/binary-search-tree-iterator/description/
#include "bits/stdc++.h"
using namespace std;
 
class BSTIterator {
private:
    void pushAll(TreeNode* node){ //push all nodes in left subtre of node
        for(;node!=NULL;st.push(node),node=node->left);
    }
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {// returns the next smaller elmnt
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {// returns whether we hv a next smaller elmnt
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */