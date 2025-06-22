// T-O(n) since we visiting all chars
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> res;
        int i=0;//start idx
        while(i<n){
            int j=(i+k-1);
            if(j>=n){//j ptr reached last idx
                j=n-1;
            }else{
                j=i+k-1;
            }
            string temp=s.substr(i,j-i+1);
            if(j-i+1<k){//full lenght couldnt get
                int rem=k-(j-i+1);
                temp+=string(rem,fill);//adding the fill elmnts to temp
            }
            res.push_back(temp);
            i+=k;
        }
        return res;
    }
};