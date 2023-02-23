//Binary search
//O(N^2(log(N))+ Nlog(N))
class Solution {
private:
    int binarySearch(vector<int>&nums,int i,int j){
         int low=j+1,high=nums.size()-1,ans=-1;
         while(low<=high){
             int mid=low+(high-low)/2;
             if(nums[i]+nums[j]>nums[mid]) low=mid+1,ans=mid;
             else high=mid-1;
         }
         return ans;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int res=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int target=nums[i]+nums[j];
                int k=binarySearch(nums,i,j);

                if(k!=-1) res+=(k-j);
            }
        }
        return res;
    }
};