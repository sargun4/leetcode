//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

class Solution{
public:
    vector<vector<int>> lvlorder(Node*root){
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int n=q.size();
            vector<int> lvl;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                lvl.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(lvl);
        }
        return res;
    }
    Node *nextRight(Node*root, int key){
        vector<vector<int>> res=lvlorder(root);
        Node*node=new Node(-1);
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                if(key==res[i][j]){
                    if(j==res[i].size()-1){//last elmnt in that lvl->no right node to that
                        return node;
                    }else{
                        node=new Node(res[i][j+1]);
                        return node;
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int key;
        cin >> key;
        cin.ignore();
        Solution obj;
        Node *res = obj.nextRight(root, key);
        cout << res->data;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends