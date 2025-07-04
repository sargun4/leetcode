#define pii pair<int,int> 
//alias- {score,id}
//1st order by pts. if pts same,lower id preferred.
class Solution {
public:
    //custom comparator for min-heap
    //priority given to higher score; if equal, to highest ID
    //removes WORST students first (lowest score, highest ID)
    struct compare {
        bool operator()(pii& a, pii& b) {
            //higher score has higher priority
            if (a.first != b.first) return a.first > b.first;
            //if scores equal, higher id has lower priority
            return a.second < b.second;
        }
    };
    int getScore(string& report,unordered_map<string,int> &feedback){
        int score=0;
        string word;
        for(int i=0;i<report.size();i++){//go over each char in report
            if(report[i]==' '){
                if(!word.empty()){
                    score+=feedback[word];//add score to word
                    word.clear();//reset for next word
                }
            }else{
                word+=report[i];
            }
        }
        if(!word.empty()) score+=feedback[word];//add last word
        return score;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n=report.size();
        //feedback map
        unordered_map<string,int> feedback;//{word:score};  
        for(string &word:positive_feedback){
            feedback[word]=3;//score=+3 for +ve
        }
        for(string &word:negative_feedback){
            feedback[word]=-1;//score=-1 for -ve
        }
        //minheap to store top k students
        priority_queue<pii,vector<pii>,compare>pq;//{pt,id}
        //calc score for each 
        for(int i=0;i<n;i++){//O(n)
            int score = getScore(report[i], feedback);
            pq.push({score,student_id[i]});//O(logk)
            if(pq.size()>k){//exceeding k students in minheap pq,need only top k
                pq.pop();//O(logk)-remove least desrving ones
            }
        }
        //get res frm heap in rev order
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=pq.top().second;//student id stored
            pq.pop();
        }
        return res;
    }
};