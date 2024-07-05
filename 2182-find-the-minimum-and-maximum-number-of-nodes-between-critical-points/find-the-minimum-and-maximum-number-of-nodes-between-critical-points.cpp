
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        int i=1;
        int prevcritposn=0;
        int firstcritposn=0;
        int mindist=INT_MAX;
        while(curr->next!=NULL){
            if((curr->val < prev->val && curr->val < curr->next->val) ||
              (curr->val > prev->val && curr->val > curr->next->val )){
                if(prevcritposn==0){
                    prevcritposn=i;
                    firstcritposn=i;
                }else{
                    mindist=min(mindist,i-prevcritposn);
                    prevcritposn=i;
                }
              }
              i++;
              prev=curr;
              curr=curr->next;
        }
        if(mindist==INT_MAX){
            return {-1,-1};
        }
        return {mindist,prevcritposn-firstcritposn};
    }
};