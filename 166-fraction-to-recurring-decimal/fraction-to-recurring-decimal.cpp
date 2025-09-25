using ll=long long;
class Solution {
public:
    string fractionToDecimal(int num, int denom) {
        if(num==0) return "0";
        string res;
        if((ll)num*(ll)denom<0){ //-ve fracn
            res+="-";
        }
        ll absNum=labs(num);
        ll absDenom=labs(denom);
        ll intDiv=absNum/absDenom;
        res+=to_string(intDiv);
        ll rem=absNum%absDenom;//remainder
        
        if(rem==0){
            return res;
        }
        res+='.';
        unordered_map<int,int> map;//{remainder:freq}
        while(rem!=0){
            if(map.count(rem)){
                res.insert(map[rem],"(");
                res+=")";
                break;
            }
            map[rem]=res.length();
            rem*=10;
            int digit=rem/absDenom;
            res+=to_string(digit);
            rem=rem%absDenom;
        }
        return res;
    }
};