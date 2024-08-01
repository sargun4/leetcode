class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int ctr=0;
        for(int i=0;i<n;i++){
            string ch=details[i];
            int age=stoi(ch.substr(11,2));
            if(age>60){
                ctr++;
            }
        }
        return ctr;
    }
};