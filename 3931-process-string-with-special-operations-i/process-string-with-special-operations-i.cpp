class Solution {
public:
    string processStr(string s) {
        vector<char> res;
        for (char ch : s) {
            if (ch != '*' && ch != '#' && ch != '%') {
                res.push_back(ch);
            }else if (ch == '#'){//duplicate curr res and append to res
                res.insert(res.end(),res.begin(),res.end());
            }else if(ch=='%'){//rev
                reverse(res.begin(), res.end());
            }else{// ch == '*' - remov last char
                if (!res.empty()) res.pop_back();
            }
        }
        return string(res.begin(), res.end());
    }
};
