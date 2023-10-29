class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=0,ans=INT_MAX;
        long long sum=0;
        unordered_map<long long,int>pref;
        vector<long long>suff(n,(long long)nums.back());

        for(int i=n-2;i>=0;i--){
            suff[i]=(long long)nums[i]+suff[i+1];
        }
        for(int i=0;i<n;i++){
            sum+=(long long)nums[i];
            pref[sum]=i;
        }
        pref[0]=-1;
        sum=0;
        for(r=0;r<n;r++){
            sum+=(long long)nums[r];
            if(sum<target) continue;
            while(l<r && sum>target) sum-=(long long)nums[l],l++;
            if(target==sum) ans=min(r-l+1,ans);
        }
        cout<<ans<<endl;
        long long total=suff[0];
        
        for(int i=0;i<n;i++){
            if(target<suff[i]) continue;
            
            long long req=target-suff[i];
            if(pref.find(req%total)==pref.end()) continue;
            int len=n-i+(req/total)*n+pref[req%total]+1;
            
            ans=min(len,ans);
        }
        
        return (ans==INT_MAX)?-1:ans;
    }
};