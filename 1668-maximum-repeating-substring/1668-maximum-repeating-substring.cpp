class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int times=100/word.size(),i=1;
        string res;
        for(;i<=times;i++){
            res+=word;
            if(sequence.find(res)==-1) break;
        }
        return i-1;
    }
};