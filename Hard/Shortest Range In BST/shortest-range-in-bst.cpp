//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



// } Driver Code Ends
// User function Template for C++


//1)smallest range in k list
// 2)level order traversal of binary tree
class Solution{
    public:
    vector<vector<int>> lvlorder(Node*root){
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> lvl;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                lvl.push_back(node->data);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        return res;
    }
    pair<int, int> shortestRange(Node* root) {
        vector<vector<int>> levels = lvlorder(root);
        int k = levels.size();
        //minheap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX, low = 0, high = 0;

        for (int i = 0; i < k; ++i) {
            pq.push({levels[i][0], i, 0});
            mx = max(mx, levels[i][0]);
        }

        while (true) {
            auto curr = pq.top(); pq.pop();
            int minVal = curr[0], levelIdx = curr[1], elemIdx = curr[2];
            if (mx - minVal < range) {
                range = mx - minVal;
                low = minVal;
                high = mx;
            }
            if (elemIdx + 1 == levels[levelIdx].size()) break;
            pq.push({levels[levelIdx][elemIdx + 1], levelIdx, elemIdx + 1});
            mx = max(mx, levels[levelIdx][elemIdx + 1]);
        }

        return {low, high};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}
// } Driver Code Ends