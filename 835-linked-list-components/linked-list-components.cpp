class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int res=0;
        while(head!=NULL){
            if(set.count(head->val)){//if head's val exist in nums
                if(head->next==NULL || !set.count(head->next->val)){//if we reached end of LL or if head's next val doesnt exist in set, that means its a breaking pt=- so we''l get 1more conn component
                    res++;
                }
            }
            head=head->next;
        }
        return res;
    }
};