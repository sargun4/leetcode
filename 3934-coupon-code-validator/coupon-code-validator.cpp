class Solution {
public:
    bool isValid(string& code){
        if(code=="") return false;
        //condn1
        for(char &ch:code){//for every char in word
            if(isalnum(ch) || ch=='_'){//if ch is alphanum and word contains '_': VALID
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    bool checkBiz(string&biz){
        if(biz=="electronics" || biz=="grocery" || biz=="pharmacy" || biz=="restaurant"){
            return true;
        }else{
            return false;
        }
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<vector<string>> res;//store {businessLine, code}
        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(isValid(code[i]) && checkBiz(businessLine[i])){
                    res.push_back({businessLine[i],code[i]});
                }
            }
        }
        sort(res.begin(),res.end());//sort first based on businessLine & then code lexically
        vector<string> ans;
        for(auto vec:res){
            string code=vec[1];
            ans.push_back(code);
        }
        return ans;
    }
};