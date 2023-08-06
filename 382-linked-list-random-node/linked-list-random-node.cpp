class Solution {
public:
    vector<int> arr;
    Solution(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
    }
    int getRandom() {
        int n=arr.size();
        int random_idx=rand()%n;
        return arr[random_idx];   
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */