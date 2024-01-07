// T-O(k+L) L=len of LL 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //1.find L-len
        int L = 0;
        ListNode* curr=head;
        while(curr!=NULL){
            curr=curr->next;
            L++;
        }
        int eachBucketsNodes=L/k;
        int remainingNodes=L%k;
        //2.create empty Bucket and fill it with nodes from the linked list
        vector<ListNode*> res(k,NULL);
        curr=head;
        ListNode* prev=NULL;
        for(int i=0;i<k;i++){
            res[i]=curr;
            for(int ctr=1;ctr<= eachBucketsNodes+(remainingNodes>0?1:0);ctr++){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL) prev->next=NULL;
            remainingNodes--;
        }
        return res;
    }
};

