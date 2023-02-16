//almost exactly similar to 424
//sliding window
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res=0,maxKey=0,tCount=0, fCount=0,r=0,l=0;
        
        for(r=0;r<answerKey.size();r++){
            (answerKey[r]=='T') ? tCount++:fCount++;
            maxKey=max(tCount,fCount);
            
            if(r-l+1-maxKey>k){
                res=max(res,(r-1)-l+1); //res=max(res,r-l+1)
                (answerKey[l]=='T') ? tCount--:fCount--;
                l++;
            }
        }
        
        return max(res,(r-1)-l+1);
    }
};