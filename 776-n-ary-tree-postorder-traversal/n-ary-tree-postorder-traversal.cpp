class Solution {
public:
    vector<int> output;
    void traverse(Node* root) {
        if(root == NULL) return;
        for(auto node:root->children)
            traverse(node);
        output.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        output.clear();
        traverse(root);
        return output;
    }
};