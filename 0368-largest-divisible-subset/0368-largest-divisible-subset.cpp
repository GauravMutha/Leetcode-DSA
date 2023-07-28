//Tabulation 2.0 from 300 Longest Increasing subsequence

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size() , maxLen=1,lastInd=0;
        vector<int>hash(n,0) , dp(n,1);
        sort(nums.begin(),nums.end());
        
        //populating hash and dp
        for(int i=1;i<n;i++){
            
            for(int pre=0;pre<i;pre++){
                
                if(nums[i]%nums[pre]==0 && (dp[pre]+1) > dp[i])
                    hash[i]=pre,dp[i]=dp[pre]+1;
            
            }
            
            if(dp[i]>maxLen) maxLen=dp[i] , lastInd=i;
        }
        
        //tracing hash to get our subsequence
        vector<int>res(maxLen,-1);
        int ptr=lastInd;
        for(int k=maxLen-1;k>=0;k--){
            res[k]=nums[ptr];
            ptr=hash[ptr];
        }
        
        return res;
        
    }
};