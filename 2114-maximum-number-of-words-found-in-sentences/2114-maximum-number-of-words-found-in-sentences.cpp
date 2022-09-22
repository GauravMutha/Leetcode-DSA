class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxwc=0,wc=0;
        for(auto str : sentences){
            wc=count(str.begin(),str.end(),' ');
            maxwc=max(maxwc,wc+1);
        }
        return maxwc;
    }
};