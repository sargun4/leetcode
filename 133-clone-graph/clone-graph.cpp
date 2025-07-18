// #include <bits/stdc++.h>
// using namespace std;
 
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
 
//deep copy
//O(v+e)
class Solution {
public:
    void dfs(Node* node,Node* copy,vector<Node*> &vis){
        vis[copy->val]=copy;
        for(auto x:node->neighbors){
            if(!vis[x->val]){
                Node* newnode=new Node(x->val);
                copy->neighbors.push_back(newnode);
                dfs(x,newnode,vis);
            }else{
                copy->neighbors.push_back(vis[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        vector<Node*> vis(1000,NULL);
        Node* copy=new Node(node->val);
        dfs(node,copy,vis);
        return copy;
    }
};