class Solution {
public:
string toHex(int num)
{
    if(num==0)return "0";
    string res={};
    vector<char>m={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    if(num>0)
        {while(num!=0){
        res+=m[num&15];
        num>>=4;}
    }
    else{
        int count=0;
        while(count<8){
            res+=m[num&15];
            count++;
            num>>=4;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
};