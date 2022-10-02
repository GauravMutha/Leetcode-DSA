class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones=0,zeroes=0,maxone=0,maxzero=0,i=0;
        
        while(i<s.size()){
            if(s[i]-'0')
                ones++ , zeroes=0;
            else
                zeroes++ , ones=0;
            maxzero=max(maxzero,zeroes);
            maxone=max(maxone,ones);
            i++;
        }
        
        return (maxone>maxzero);
    }
};