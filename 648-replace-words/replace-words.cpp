class Solution {
public:
    string findroot(string&word,unordered_set<string> &st){
        for(int l=1;l<=word.length();l++){
            string root=word.substr(0,l);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(begin(dictionary),end(dictionary));
        string word;
        stringstream ss(sentence);
        string res;
        while(getline(ss,word,' ')){
            res+=findroot(word,st)+" ";
        }
        res.pop_back();
        return res;
    }
};