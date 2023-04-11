//Re//
//Simple concept of subsets printing
//Classic two rec calls pick not pick method
class Solution {
private:
    int count=0;
public:
    void helper(int i,int or_sum,vector<int>& nums,int k){
        if(i>=nums.size()){
            if(or_sum==k) count++;
            return;
        }
        int tempSum=or_sum;
        tempSum|=nums[i];
     
        helper(i+1,tempSum,nums,k);
    
        helper(i+1,or_sum,nums,k);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0;
        vector<int>ds;
        for(int i=0;i<nums.size();i++){
            maxOR|=nums[i];
        }
        helper(0,0,nums,maxOR);
        
        return count;
    }
};