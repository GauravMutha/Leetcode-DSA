//Tabulation
//Space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        int secondLast=0 , last=nums[0], curr;
        
        int res=max(secondLast,last);
        for(int i=1;i<nums.size();i++){
            curr=max((nums[i]+secondLast),last);
            res=max(res,curr);
            secondLast=last;
            last=curr;
        }
        return last;
    }
};