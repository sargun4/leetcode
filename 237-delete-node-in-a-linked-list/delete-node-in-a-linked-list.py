# class Solution {
# public:
#     void deleteNode(ListNode* node) {
#         ListNode *prev=NULL;
#         while(node!=NULL && node->next!=NULL){
#             node->val=node->next->val;
#             prev=node;
#             node=node->next;
#         }
#         prev->next=NULL;
#         delete(node);
#     }
# };
class Solution:
    def deleteNode(self, node):
        prev=None
        while(node and node.next):
            node.val=node.next.val
            prev=node
            node=node.next
        prev.next=None
        del(node)
        