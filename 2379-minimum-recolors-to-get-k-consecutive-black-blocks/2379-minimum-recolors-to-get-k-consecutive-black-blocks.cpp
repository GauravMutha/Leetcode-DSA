class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0,r=0,countw=0,res=0;
        
        while(k-- && r<blocks.size())
            countw+=(blocks[r++]=='W');
        r--;
        res=countw;
        
        while(r<blocks.size()){
            if(++l>=blocks.size() || ++r>=blocks.size()) break;
            countw-=(blocks[l-1]=='W');
            countw+=(blocks[r]=='W');
            res=min(countw,res);
        }
        return res;
    }
};