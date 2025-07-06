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
        priority_queue<int> pq;//maxheap
        while(k--){//run till we hv done k projects
            while(i<n && vec[i].first<=w){//if cost of proj <starting capital
                pq.push(vec[i].second);//we can take it-so add profit to pq
                i++;//nxt idx
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();//max profit at top-maxheap
            pq.pop();//remove it frm pq since we hv now done this proj
        }
        return w;//our max final capital after doing k projs
    }
};