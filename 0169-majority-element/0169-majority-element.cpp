//Most Optimal Solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElement=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majorElement) count++;
            else count--;
            
            if(count==0) majorElement=nums[i] , count=1;
        }
        
        return majorElement;
    }
};