class Solution {
public:
    unordered_set<string> exactSet;
    unordered_map<string,string> caseMap;
    unordered_map<string,string> vowelMap;

    string toLower(string &s){
        string ans=s;
        for(char&ch:ans){
            ch=tolower(ch);
        }
        return ans;
    }
    string replacevowel(string&s){
        string ans=s;
        for(char&ch:ans){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                ch='*';
            }
        }
        return ans;
    }
    string checkForMatch(string &query){
        if(exactSet.count(query)){
            return query;
        }
        //case error check
        string lowercase=toLower(query);
        if(caseMap.count(lowercase)){
            return caseMap[lowercase];
        }
        //vwel error check
        string vowelcase=replacevowel(lowercase);
        if(vowelMap.count(vowelcase)){
            return vowelMap[vowelcase];
        }
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMap.clear();
        vowelMap.clear();
        for(string word:wordlist){
            exactSet.insert(word);
            string lowercase=toLower(word);
            //if lower not in caseMap yet, then add it
            if(caseMap.find(lowercase)==caseMap.end()){
                caseMap[lowercase]=word;
            }
            string vowelcase=replacevowel(lowercase);
            if(vowelMap.find(vowelcase)==vowelMap.end()){
                vowelMap[vowelcase]=word;
            }
        }
        vector<string> ans;
        for(string &query:queries){
            ans.push_back(checkForMatch(query));
        }
        return ans;
    }
};