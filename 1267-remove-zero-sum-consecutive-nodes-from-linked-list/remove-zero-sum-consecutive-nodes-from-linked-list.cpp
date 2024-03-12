 
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        unordered_map<int, ListNode*> map; 
        map[0] = dummyNode;
        int prefSum = 0;

        while(head != nullptr){
            prefSum += head->val;
            if(map.find(prefSum) != map.end()){//if that prefsum present in map
                ListNode* start = map[prefSum]; //start->next to head [delete all]
                int pf = prefSum;
                ListNode* temp = start;
                while(temp->next != head){
                    temp = temp->next;
                    pf += temp->val;
                    map.erase(pf);
                }
                start->next = head->next;
            }else{//if that prefsum not present in map
                map[prefSum] = head;
            }
            head = head->next;
        }

        ListNode* newHead = dummyNode->next;
        delete(dummyNode);
        return newHead;
    }
};