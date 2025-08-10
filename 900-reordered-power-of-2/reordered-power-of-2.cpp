class Solution {
public:
    string getSortedStr(int n){
        string s=to_string(n);//10 digits
        sort(begin(s),end(s));
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s=getSortedStr(n);
        //check all 2 powersn see if it matches w s
        for(int p=0;p<=29;p++){
            if(s==getSortedStr(1<<p)){
                return true;
            }
        }
        return false;
    }
};