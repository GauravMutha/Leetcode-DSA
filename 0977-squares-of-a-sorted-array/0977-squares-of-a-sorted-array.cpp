class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int l=0 , r=nums.size()-1,k=nums.size()-1;
        vector<int>res(nums.size(),0);
        
        while(l<=r){
            int lsq=nums[l]*nums[l] , rsq=nums[r]*nums[r];
            if(lsq>rsq){
                res[k--]=lsq , l++;
            }
            else res[k--]=rsq , r--;
        }
        
        return res;
    }
};