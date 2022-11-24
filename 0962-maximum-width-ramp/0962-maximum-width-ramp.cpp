class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=-1,n=nums.size();
        vector<int>rMax(n,0);
        rMax.back()=nums.back();
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(nums[i],rMax[i+1]);
        }
        for(int l=0,r=0;r<n;r++){
            while(l<n && nums[l]>rMax[r]) l++;
            
            ans=max(ans,r-l);
        }
        return ans;
    }
};

//2 pass
//TC--> O(n)
//SC-->O(1)