class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> pq;//maxheap
        int sum=0;
        for(int i=0;i<n;i++){//for each stone in the pile
            pq.push(piles[i]);//push it in maxheap
            sum+=piles[i]; //add to sum
        }
        for(int i=0;i<k;i++){
            int maxelmnt=pq.top();//get the max elmnt
            pq.pop();
            int remove_half=maxelmnt/2;//remove half stones frm it
            sum-=remove_half;
            maxelmnt-=remove_half;
            pq.push(maxelmnt);
        }
        return sum;
    }
};