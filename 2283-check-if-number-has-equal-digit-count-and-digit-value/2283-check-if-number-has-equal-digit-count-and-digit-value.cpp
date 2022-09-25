class Solution {
public:
    bool digitCount(string num) {
        string res(num.size() , '0');
        int i=0;
        for(i=0;i<num.size() && ((num[i]-'0')<num.size());i++)
            res[num[i]-'0']++;
        
        if(i==num.size() && (res==num)) return true;
        return false;    
    }
};