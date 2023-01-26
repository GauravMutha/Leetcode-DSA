//Priority Queue Max Heap
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<double>maxh;
        int total=0,removed=0;
        for(auto &num : piles)
            maxh.push(num) , total+=num;
        
        while(k--){
            double val=maxh.top();
            maxh.pop();
            removed+=(val-ceil(val/2));
            maxh.push(ceil(val/2));
        }
        
        return total-removed;
    }
};