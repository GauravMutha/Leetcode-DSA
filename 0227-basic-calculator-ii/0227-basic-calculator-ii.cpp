class Solution {
public:
    int calculate(string s) {
        int curr=0,intRes=0,ans=0;
        char prevOp='+';
        s+="##";
        for(auto c : s){
            if(c==' ') continue;
            else if(isdigit(c)) curr=curr*10 + (c-'0');
            else{
                if(prevOp=='*') intRes*=curr;
                else if(prevOp=='/') intRes/=curr;
                else ans+=intRes , intRes=(prevOp=='+')?curr:-curr;
                
                prevOp=c;
                curr=0;
            }
        }
        return ans;
    }
};

//Without Stack
//SC-->O(1)
//TC-->O(n)