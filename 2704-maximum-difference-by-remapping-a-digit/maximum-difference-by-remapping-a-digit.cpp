class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string max = "";
        string min = "";
        int n = str.size();
        char ele = ' ';
        //Find first non-9 digit for max replacement
        for(int i=0;i<n;i++){
            if(str[i] != '9'){
                ele = str[i];
                break;
            }
        }
        //Replace that digit with 9 for max
        for(int i=0;i<n;i++){
            if(ele == str[i]) max += '9';
            else max += str[i];
        }
        //Replace first digit for min with 0
        for(int i=0;i<n;i++){
            if(str[0] == str[i]) min += '0';
            else min += str[i];
        }
        //Convert and calculate result
        return stoi(max) - stoi(min);
    }
};