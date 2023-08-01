//Revising second approach ( O(1) SC)
class Solution {
public:
    int trap(vector<int>& nums) {
        int l=0,n=nums.size() , r=n-1;
        int maxLeft=-1,maxRight=-1,res=0;
        
        while(l<r){
            if(nums[l]<=nums[r]){
                if(nums[l]>=maxLeft) maxLeft=nums[l];
                else res+=(maxLeft-nums[l]);
                l++;
            }
            else{
                if(nums[r]>=maxRight) maxRight=nums[r];
                else res+=(maxRight-nums[r]);
                r--;
            }
        }
        
        return res;
    }
};