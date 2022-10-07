class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1,val=0,sum=0,carry=0;
        string res;
        
        while(i>=0 || j>=0 || carry){
            val=0,sum=0;
            if(i>=0) val+=num1[i--]-'0';
            if(j>=0) val+=num2[j--]-'0';
            sum=(val+carry)%10;
            carry=(val+carry)/10;
            res=to_string(sum)+res;
        }
        return res;
    }
};