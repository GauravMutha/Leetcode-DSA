//O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if((nums[l]+nums[r])>target) r--;
                else if((nums[l]+nums[r])<target) l++;
                else{
                    vector<int>triplets={nums[i],nums[l],nums[r]};
                    res.push_back(triplets);
                    while(l<r && nums[l]==triplets[1]) l++;
                    while(l<r && nums[r]==triplets[2]) r--;
                }
            }
        }
        return res;
    }
};