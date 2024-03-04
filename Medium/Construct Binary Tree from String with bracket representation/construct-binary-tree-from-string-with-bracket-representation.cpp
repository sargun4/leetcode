//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++
 
class Solution {
public:
    Node* solve(string s, int &idx) {
        if (idx >= s.length() || s[idx] == ')') {
            idx++;
            return NULL;
        }
        string str = "";
        while (s[idx] >= '0' && s[idx] <= '9') {
            str += s[idx];
            idx++;
        }

        Node* ans = new Node(stoi(str));

        if (s[idx] == '(') {
            idx++;
            ans->left = solve(s, idx);
        }

        if (s[idx] == '(') {
            idx++;
            ans->right = solve(s, idx);
        }

        idx++;
        return ans;
    }

    Node* treeFromString(string str) {
        int idx = 0;
        return solve(str, idx);
    }
};
 

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends