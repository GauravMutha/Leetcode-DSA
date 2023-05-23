//using  the best approach of 3Sum 
//O(n^3)
class Solution {
private:
    vector<vector<int>>res;
public:
    void threeSum(int ind,vector<int>& nums,int firstFixed,long long target) {
        
        for(int i=ind+1;i<nums.size()-2;i++){
            if(i!=(ind+1) && nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            long long threeSumTarget=target-(long long)nums[i];
            while(l<r){
                long long sum=(long long)nums[l]+(long long)nums[r];
                if(sum>threeSumTarget) r--;
                else if(sum<threeSumTarget) l++;
                else{
                    vector<int>quadruplets={firstFixed,nums[i],nums[l],nums[r]};
                    res.push_back(quadruplets);
                    while(l<r && nums[l]==quadruplets[2]) l++;
                    while(l<r && nums[r]==quadruplets[3]) r--;
                }
            }
        }
        return;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return res; //an empty res is returned
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            threeSum(i,nums,nums[i],target-nums[i]);
        }
        
        return res;
    }
};