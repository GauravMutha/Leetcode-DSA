//two pointers
//TC--> O(m*log(n)) m is the size of nums1 , n is of nums2
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist=0,low=0,high=0,sz1=nums1.size(),sz2=nums2.size(),res=0;
        
        for(int i=0;i<nums1.size();i++){
            int mid=0 , low=i,high=nums2.size()-1;
            while(low<=high){
                mid=low + (high-low)/2;
                if(nums2[mid]>=nums1[i])
                    maxDist=max(mid-i,maxDist) , low=mid+1;
                else high=mid-1;
            }
            res=max(res,maxDist);
        }
        return res;
    }
};