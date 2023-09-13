class Solution {
public:
    int trap(vector<int>& nums) {
        int res=0,n=nums.size(),l=0,r=n-1,leftMax=-1,rightMax=-1;
        
        for(int i=0;i<n;i++){
            if(nums[l]<=nums[r]){
                if(nums[l]>=leftMax) leftMax=nums[l];
                else res+=(leftMax-nums[l]);
                l++;
            }
            else{
                if(nums[r]>=rightMax) rightMax=nums[r];
                else res+=(rightMax-nums[r]);
                r--;
            }
        }
        return res;
    }
};