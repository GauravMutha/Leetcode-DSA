//Bianry search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size(),res=1;
        vector<int>vec{nums[0]};
        
        for(int i=1;i<n;i++){
            
            if(nums[i]>vec.back()) vec.push_back(nums[i]);
            else{
                int x=lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin();
                vec[x]=nums[i];
            }
        }
        
        return vec.size();
    }
};