//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}


// } Driver Code Ends
// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/
class Solution{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key){
            if(key.length()==0){
                root->isLeaf = true;
                return;
            }
            int idx=key[0]-'a';
            TrieNode* temp;
            //when word is present
            if(root->children[idx]!=NULL){
                temp=root->children[idx];
            }
            //when word is absent
            else{
                temp=new TrieNode();
                root->children[idx]=temp;
            }
            //recursively call for remaining string
            insert(temp,key.substr(1));
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) {
            if(key.length()==0){
                return root->isLeaf;
            }
            int idx=key[0]-'a';
            TrieNode* temp;
            //when word is present
            if(root->children[idx]!=NULL){
                temp=root->children[idx];
            }
            //when word is absent
            else{
                return false;
            }
            //recursively call for remaining string
            return (search(temp,key.substr(1))); 
        }
};

//{ Driver Code Starts.

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        
        Solution obj;
        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) obj.insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (obj.search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends