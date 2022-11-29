class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long mod=1e9+7,ans=0;
        int n=nums.size();
        vector<int> nSmall(n,-1) , pSmall(n,-1);
        vector<long long>preSum(n+1);
        stack<int>st;
        
        //prefix sum
        for(int i=0;i<n;i++)
            preSum[i+1]=preSum[i]+nums[i];
        //next smaller element to left
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) pSmall[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //next smaller element to right
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) nSmall[i]=st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            long long val= nSmall[i]==-1 ? preSum.back() :preSum[nSmall[i]];
            if(pSmall[i]!=-1) val-=preSum[pSmall[i]+1];
            ans=max(ans,(long long)nums[i]*val);
        }
        
        return ans%mod;
    }
};

//Just like 2104.Sum of subarray ranges
//SC-->O(N)
//TC-->O(N)