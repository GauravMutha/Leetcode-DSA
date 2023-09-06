class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long res=0;
        int prefix=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        
        for(auto num : nums){
            prefix=(prefix+((num%mod==k)?1:0))%mod;
            res+=mp[(prefix-k+mod)%mod];
            mp[prefix]++;
        }
        
        return res;       
    }
};
