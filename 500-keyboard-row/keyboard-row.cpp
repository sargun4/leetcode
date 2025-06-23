class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char,int> map;
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        for(char &ch:s1) map[tolower(ch)]=1;
        for(char &ch:s2) map[tolower(ch)]=2;
        for(char &ch:s3) map[tolower(ch)]=3; 
        //for each word, check if all chars belong to the same row as the first char
        for(string &word:words){
            int row1=map[tolower(word[0])];
            bool flag=true;
            for(char &ch:word){
                if(map[tolower(ch)]!=row1){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};