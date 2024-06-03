/*
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// class Solution {
// public:
//     vector<int> res;
//     void traverse(Node* root) {
//         if(root == NULL) return;
//         for(auto node:root->children)
//             traverse(node);
//         res.push_back(root->val);
//     }
//     vector<int> postorder(Node* root) {
//         res.clear();
//         traverse(root);
//         return res;
//     }
// };

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        stack<Node*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            Node* node=st.top(); 
            st.pop();
            int size=node->children.size();
            ans.push_back(node->val);
            for(int i=0;i<size;i++){
                if(node->children[i])
                    st.push(node->children[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};