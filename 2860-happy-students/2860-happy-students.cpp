class Solution {
public:
    int countWays(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int selected=i+1;
            if(nums[i]<selected && nums[i+1]>selected) res++;
        }
        
        return (res+(nums[0]!=0)+1);
    }
};