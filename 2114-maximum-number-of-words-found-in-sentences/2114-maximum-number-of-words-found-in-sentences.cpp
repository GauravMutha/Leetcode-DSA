class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxwc=0,wc=1;
        for(auto str : sentences){
            wc=1;
            for(auto c:str){
                if(c==' ')wc++;
            }
            maxwc=max(maxwc,wc);
        }
        return maxwc;
    }
};