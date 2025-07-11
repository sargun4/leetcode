//{ Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

long long unsigned int decimalValue(struct Node *head);

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

        cout << decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Below global variable is declared in code for modulo arithmetic
// const long long unsigned int MOD = 1000000007;

// Should return decimal equivalent modulo 1000000007 of binary linked list
long long unsigned int decimalValue(Node *head){
    if (head == NULL) return 0;
    Node *temp = head;
    long long unsigned int mod = 1000000007, sum = 0;
    while (temp){
        sum  = (sum*2+temp->data) % mod ;
        temp = temp->next;
    }return (sum) ;
}
