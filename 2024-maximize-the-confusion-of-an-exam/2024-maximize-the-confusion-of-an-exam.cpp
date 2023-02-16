//a optimisation on brute force O(n*n)
//Binary search
//TC-->(n*log(n));
class Solution {
private:
    vector<int>tPre , fPre;
    
    int binarySearch(int i,int k,string &key){
        int start=i,end=key.size()-1, j=0;
        
        while(start<=end){
            int mid=start  + (end-start)/2;
            int tCount=(i>0) ? tPre[mid]-tPre[i-1] : tPre[mid];
            int fCount=(i>0) ? fPre[mid]-fPre[i-1] : fPre[mid];
            int maxKey=max(tCount,fCount);
            if(mid-i+1-maxKey>k) end=mid-1;
            else j=mid , start=mid+1;
        }
        
        return j;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res=0,fSum=0,tSum=0;
        
        for(auto & ch : answerKey){
            tSum+=(ch=='T') , fSum+=(ch=='F');
            tPre.push_back(tSum) , fPre.push_back(fSum);
        }
        for(int i=0;i<answerKey.size();i++){
            int j=binarySearch(i,k,answerKey);
            res=max(res,j-i+1);
        }
        
        return res;
    }
};