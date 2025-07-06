class Solution {
public:
    typedef pair<char,int> p;//{char,idx}

    struct comp{//comparator
        bool operator()(p&p1,p&p2){
            if(p1.first==p2.first){//if chars are equal, higher idx shd be given more priority
                return p1.second<p2.second;
            }
            return p1.first>p2.first;//smaller char at top of pq
        }
    };
    string clearStars(string s) {
        int n=s.length();
    //minheap-smallest char at top,incase of tie- largest idx at top shd be there
        priority_queue<p,vector<p>,comp> pq;//{char:idx}
        for(int i=0;i<n;i++){//goin over all chars in str
            if(s[i]!='*'){
                pq.push({s[i],i});
            }else{//star at that char
                int idx=pq.top().second;
                pq.pop();
                s[idx]='*';//char to now be deleted frm str
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};