//Floyd's detection
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0,i=0;
        do{
            slow=nums[slow];
            
            fast=nums[fast];
            fast=nums[fast];
        }while(slow!=fast);
        
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};