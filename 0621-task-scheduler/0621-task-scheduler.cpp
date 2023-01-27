//TC-->O(N)
//SC--> O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);
        int max=0 , maxCount=0;
        for(auto &c : tasks){
            hash[c-'A']++;
            if(max==hash[c-'A']) maxCount++;
            else if(hash[c-'A'] > max) max=hash[c-'A'] , maxCount=1;
        }
        
        int partCount=max-1;
        int partLength=n-(maxCount-1);
        int emptySlots=partCount*partLength;
        int availableTasks=tasks.size() - max*maxCount;
        int idleSlots= ((emptySlots-availableTasks)<= 0)?0:emptySlots-availableTasks;
        
        return tasks.size()+idleSlots;
    }
};