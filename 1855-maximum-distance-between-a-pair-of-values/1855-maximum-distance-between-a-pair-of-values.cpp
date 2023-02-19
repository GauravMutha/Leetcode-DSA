//two pointers
//TC--> O(min(m,n))
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist=0,i=0,j=0,sz1=nums1.size(),sz2=nums2.size();
        
        while(i<sz1 && j<sz2){
            if(nums1[i]<=nums2[j]){
                if(j>=i) maxDist=max(maxDist,j-i);
                j++;
            }
            else i++;
        }
        return maxDist;
    }
};