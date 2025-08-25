class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        vector<string> big={"Thousand","Million","Billion"};
        string ans=solve(num%1000);
        num=num/1000;
        for(int i=0;i<3;i++){
            if(num>0 && num%1000 > 0){
                ans=solve(num%1000) + big[i] +" "+ ans;
            }
            num=num/1000;
        }
        if(ans.empty()){
            return {};
        }
        return ans.substr(0,ans.size()-1);
    }
    string solve(int num){
        vector<string>digits={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string>teens= {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string>tens= {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string ans="";
        if(num>99){
            ans+=digits[num/100]+" Hundred ";
        }
        num%=100;
        if(num<20 && num>9){//teens
            ans+=teens[num-10]+" ";
        }else{
            if(num>=20){
                ans+=tens[num/10]+" ";
            }
            num%=10;
            if(num>0){
                ans+=digits[num]+" ";
            }
        }
        return ans;
    }
};