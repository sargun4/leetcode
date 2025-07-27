class Solution {
  public:
    void deleteAlt(struct Node*head) {
        Node* curr=head; 
        // Node* prev=NULL;
        while(curr!=NULL && curr->next!=NULL){
            curr->next=curr->next->next;
            curr=curr->next;
        }
    }
};