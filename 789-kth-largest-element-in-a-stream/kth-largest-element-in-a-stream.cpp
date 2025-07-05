class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<>> pq;//minheap
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int&num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();//min elmnt popped out, if size exceeds k
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();//min elmnt popped out, if size exceeds k
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */