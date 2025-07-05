//get highest freq at top in maxheap-{freq,char}; and after adding in str reduce its freq 
class Solution {
public:
    typedef pair<int,char> p;
    string reorganizeString(string s) {
        int n=s.length();
        vector<int> ctr(26,0);
        for(char &ch:s){
            ctr[ch-'a']++;
        }
        for(int freq:ctr){
            if(freq > (n+1)/2){
                return "";//empty str since we wont b able to get any str if freq of any 1 char >(n+1)/2 so impossible to rearrange
            }
        }
        //maxheap-at top, highest freq of char stored
        priority_queue<p,vector<p>> pq; //{freq,char}
        for(int i=0;i<26;i++){
            char ch=i+'a';
            if(ctr[i]>0){//if freq>0,push it in pq
                pq.push({ctr[i],ch});
            }
        }
        string ans="";
        //making string by slecting top 2chars
        while(pq.size()>=2){
            //top 2 chars-most freq 2
            p p1=pq.top(); pq.pop();
            p p2=pq.top(); pq.pop();
            int freq1=p1.first;
            char char1=p1.second;
            int freq2=p2.first;
            char char2=p2.second;
            //add both chars to ans
            ans.push_back(char1); freq1--;
            ans.push_back(char2); freq2--;
            //decrease their freqs and push back into pq if still availabl
            if(freq1>0) pq.push({freq1, char1});
            if(freq2>0) pq.push({freq2, char2});
        }
        if(!pq.empty()){//1elmnt left
            if(pq.top().first>1) return ""; //more than 1 left- Not valid
            int ch=pq.top().second;
            ans.push_back(ch);
        }
        return ans;
    }
};