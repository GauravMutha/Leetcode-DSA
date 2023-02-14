//Binary Search
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1 , end=1e9;
        while(low<end){
            int aspiredPenalty=low+ (end-low)/2;
            
            int splitOperations=0;
            for(auto &balls : nums){
                if(balls<=aspiredPenalty) continue;
                
                if(balls%aspiredPenalty)
                    splitOperations+=(balls)/aspiredPenalty;
                else 
                    splitOperations+=(balls-1)/aspiredPenalty;
            }
            
            if(splitOperations>maxOperations)
                low=aspiredPenalty+1;
            
            else end=aspiredPenalty;
        }
        
        return low;
    }
};