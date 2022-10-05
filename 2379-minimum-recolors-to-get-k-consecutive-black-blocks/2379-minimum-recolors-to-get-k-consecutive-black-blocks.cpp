class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0,r=0,countw=0,res=INT_MAX;
        
        while(((r-l+1)<=k) && (r<blocks.size())){
            countw+=(blocks[r]=='W');
            r++;
        }
        r--;
        res=min(countw,res);
        
        while(r<blocks.size()){
            l++;
            r++;
            if(l>=blocks.size() || r>=blocks.size()) break;
            countw-=(blocks[l-1]=='W');
            countw+=(blocks[r]=='W');
            if(countw==0) return 0;
            res=min(countw,res);
        }
        return res;
    }
};