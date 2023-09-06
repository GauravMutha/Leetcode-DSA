class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long res=0;
        
        vector<int>prefix(nums.size(),0);
        prefix[0]=((nums[0]%mod)==k) ? 1 : 0;
        
        unordered_map<int,int>mp;
        mp[0]=1;
        
        for(int i=1;i<nums.size();i++){
            int x=((nums[i]%mod)==k);
            prefix[i]=(prefix[i-1]+(x ? 1 : 0));
        
        }
        for(int i=0;i<nums.size();i++){
            
            cout<<prefix[i]<<endl;
            
            int find=prefix[i]%mod-k;
            if(find<0) find+=mod;
            res+=mp[find];
            mp[prefix[i]%mod]++;
        }
        
        return res;
    }
};