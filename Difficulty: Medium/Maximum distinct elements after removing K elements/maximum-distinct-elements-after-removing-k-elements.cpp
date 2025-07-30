class Solution {
  public:
    // Function to find the maximum number of distinct elements after removing k
    // elements.
    int maxDistinctNum(vector<int> arr, int k) {
        unordered_map<int,int> map;//{num:freq}
        for(auto num:arr){
            map[num]++;
        }
        priority_queue<int> pq;//maxheap
        for(auto it:map){
            int freq=it.second;
            pq.push(freq);
        }
        for(int i=0;i<k;i++){
            int top=pq.top();//freq
            pq.pop();
            if(top-1!=0){//if freq not 0
                pq.push(top-1);
            }
        }
        return pq.size();
    }
};