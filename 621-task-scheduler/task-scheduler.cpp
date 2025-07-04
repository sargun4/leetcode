// selecting the task with lowest freq increases idle time for the scheduler, thereby failing to maximize efficiency. Conversely, choosing tasks with higher freqs maximizes efficiency.
// so use maxheap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);//freq of each task
        for(char&ch:tasks){
            freq[ch-'A']++;
        }
        //maxheap-to store freqs
        priority_queue<int> pq;
        for(int f:freq){
            if(f>0) pq.push(f);
        }
        int time=0;
        while(!pq.empty()){
            int cycles=n+1;//total slots in cpu cycle
            vector<int> temp;//to store remnaing freqs that still hv to be procssd
            int taskctr=0;//track no of task processd in curr cylce
            while(cycles>0 && !pq.empty()){
                int curr=pq.top(); pq.pop();
                if(curr>1){//will hv to come again in a later cycle
                    temp.push_back(curr-1);
                }
                time++;//task executd
                cycles--;
            }
            //re insert tasks that need processing
            for(int remfreq:temp){
                pq.push(remfreq);
            }
            //if tasks remain,cycle wasnt full, so add idle time
            if(!pq.empty()){
                time+=cycles;//fill remainaing cycle slots as idle
            }
        }
        return time;
    }
};