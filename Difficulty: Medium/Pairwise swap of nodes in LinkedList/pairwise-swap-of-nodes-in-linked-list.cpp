struct Node* pairwise_swap(struct Node* head) {
    Node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        int temp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=temp;
        curr=curr->next->next;
    }
    return head;
}
// //TLE
// Node* revknodes(Node* head,int k){
//     Node* prev;
//     Node* curr=head;
//     Node* temp;
//     int ctr=0;
//     while(curr!=NULL && ctr<k){
//         temp=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=temp;
//         ctr++;
//     }
//     if(temp!=NULL){
//         head->next=revknodes(curr,k);
//     }
//     return prev;//new head of revLL
// }
// // Function to swap elements pairwise.
// struct Node* pairwise_swap(struct Node* head) {
//     head=revknodes(head,2);
//     return head;
// }