 //a camera node can monitor 4nodes-itself,its parent & its left n right children; 
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    unordered_map<TreeNode*, bool> vis;

    //convert binary tree to undir graph
    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        if (parent){
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }
    //dfs return state of node
    // 0=Not covered, 1=Has camera, 2=covered(by child)
    int dfs(TreeNode* node, TreeNode* parent, int &cameraCount) {
        vis[node] = true;
        bool hasChildNotCovered = false;//atleast 1 child is not covered
        bool hasChildWithCamera = false;//atleast 1 child has a camera

        for (TreeNode* neighbor : graph[node]) {
            if (neighbor == parent || vis[neighbor]) continue;

            int childState = dfs(neighbor, node, cameraCount);
        //if child isnt covered, we may need to place a camera at this node
            if (childState == 0) hasChildNotCovered = true;
            //if child has camera, this node is covered
            if (childState == 1) hasChildWithCamera = true;
        }
        //if any child isnt covered, place a camera here
        if (hasChildNotCovered) {
            cameraCount++;
            return 1; // Place camera here
        }
        //if any child has a camera, this node is already covered
        if (hasChildWithCamera) {
            return 2; // This node is covered
        }
    //no child has camera, all are covered -> this node is not covered
        return 0; // This node is not covered
    }

    int minCameraCover(TreeNode* root) {
        if (!root) return 0;

        buildGraph(root, nullptr);
        int cameraCount = 0;
        //if root is still not covered after DFS, we must place a camera at root
        int rootState = dfs(root, nullptr, cameraCount);
        if (rootState == 0) {
            cameraCount++; // Root needs camera
        }
        return cameraCount;
    }
};
