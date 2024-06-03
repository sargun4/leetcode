class Solution {
public:
    vector<string> table {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
            "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string convertor(string &s){
        string res;
        for(auto ch:s){
            res+=table[ch - 'a'];
        }
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for(auto &ch : words){
            s.insert(convertor(ch));
        }
        return s.size();
    }
};