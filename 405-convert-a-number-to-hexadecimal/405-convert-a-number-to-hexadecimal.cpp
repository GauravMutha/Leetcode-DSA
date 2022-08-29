class Solution {
public:
    string toHex(int num) {
        if(num==0)return "0";
        vector<char>hexsymb={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string res={};
        if(num>0){
            while(num!=0){
                res+=hexsymb[num&15];
                num>>=4;
            }
        }
        else{
            int count=0;
           while(count<8){
               res+=hexsymb[num&15];
               count++;
               num>>=4;
           } 
        }
        reverse(res.begin(),res.end());
        return res;
    }
};