class Solution {
public:
    int getLucky(string s, int k) {
        int val,res=0;
        string temp;
        
        for(auto c:s){
            val=c-'a'+1;
            temp+=(to_string(val));
        }
        
        while(k--){
            res=0;
            for(auto c:temp)
                res+=(c-'0');
            temp=to_string(res);
        }
        
        return res;
    }
};