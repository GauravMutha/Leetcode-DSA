class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idiff, int vdiff) {
        int i=0,n=nums.size(),mini=nums[0],maxi=nums[0];
        
        vector<int>minPref(n,0),maxPref(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]<=mini) minPref[i]=i,mini=nums[i];
            else minPref[i]=minPref[i-1];
            if(nums[i]>=maxi) maxPref[i]=i, maxi=nums[i];
            else maxPref[i]=maxPref[i-1];
            
            cout<<minPref[i]<<" "<<maxPref[i]<<endl;
        }
        
        for(int i=0;i<n;i++){
            if(i<idiff) continue;
            
            int lb=nums[i]-vdiff , ub=nums[i]+vdiff;
            int maxti=nums[maxPref[i-idiff]],minti=nums[minPref[i-idiff]];
            
            if(maxti>=ub) return {maxPref[i-idiff],i};
            if(minti<=lb) return {minPref[i-idiff],i};
        }
        
        return {-1,-1};
    }
};