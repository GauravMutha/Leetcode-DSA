class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFreq =0 , maxFreqCount=0;
        vector<int>hash(26,0);
        for(auto &c : tasks){
            int freq=++hash[c-'A'];
            if(freq==maxFreq) maxFreqCount++;
            else if(freq>maxFreq) maxFreq=freq, maxFreqCount=1;
        }
        
        int fillerBlocks=maxFreq-1;
        int emptySlots=fillerBlocks*(n-(maxFreqCount-1));
        int remainingTasks=tasks.size()-maxFreq*maxFreqCount;
        int idles=max(0,emptySlots-remainingTasks);
        
        return (tasks.size()+idles);
        
    }
};