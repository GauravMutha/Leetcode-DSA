//Binary search
class Solution {
public:
    bool check(vector<long long>& preSum,int groups){
        
        for(int i=preSum.size()-1;i>=0 && groups;i--){
            
            //sum of all avialable elements till this index
            long long sum=(long long)groups*(long long)(groups+1)/2;
            
            if((i+1)>=groups && preSum[i]>=sum)
                groups--;
            
            else return false;
        }
        
        return true;
    }
    int maxIncreasingGroups(vector<int>& limits) {
        sort(limits.begin(),limits.end());
        int low=1 , high=limits.size() , n=limits.size();
        
        vector<long long>pre(n);
        pre[0]=limits[0];
        for(int i=1;i<limits.size();i++)
            pre[i]=pre[i-1]+limits[i];
        
        int ans=0;
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(check(pre,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return ans;
    }
};