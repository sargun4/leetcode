class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;//maxheap- store stones
        for(int &stone:stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int max1=pq.top(); pq.pop();
            int max2=pq.top(); pq.pop();
            pq.push(abs(max1-max2));
        }
        return pq.top();
    }
};