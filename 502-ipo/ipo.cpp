class Solution {//TC-O(nlogn),SC-O(n)
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size(); 
        vector<pair<int,int>> vec(n);//{cost/capital_req,profit}
        for(int i=0;i<n;i++){
            vec[i]={capital[i],profits[i]};
        }
        sort(begin(vec),end(vec));//sort based on capital
        int i=0;//to iter on vec
        priority_queue<int> pq;//maxheap to store max profits at top
        while(k--){//run till we hv done k projects
            //add all projs that can be started with current capital
            while(i<n && vec[i].first<=w){//if cost of proj <starting capital
                pq.push(vec[i].second);//we can take it-so add profit to pq
                i++;//nxt idx
            }
            if(pq.empty()){//if no projs r affordable now, break early
                break;
            }
            w+=pq.top();//add max profit (at top of maxheap) to w
            pq.pop();//remove it frm pq since we hv now done this proj
        }
        return w;//our max final capital after doing k projs
    }
};