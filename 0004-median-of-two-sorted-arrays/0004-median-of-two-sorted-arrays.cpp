//Naive than previous
//TC-->O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ptr1=0 , ptr2=0 , n1=nums1.size() , n2=nums2.size(),mark=(n1+n2)/2+1;
        int prev=-1 , curr=-1 , count=0;
        while(ptr1<n1 && ptr2<n2 && count<mark){
            count++;
            if(nums1[ptr1]<=nums2[ptr2]){
                prev=curr;
                curr=nums1[ptr1];
                ptr1++;
            }
            else{
                prev=curr;
                curr=nums2[ptr2];
                ptr2++;
            }
        }
        
        while(ptr1<n1 && count<mark){
            count++;
            prev=curr;
            curr=nums1[ptr1];
            ptr1++;
        }
        while(ptr2<n2 && count<mark){
            count++;
            prev=curr;
            curr=nums2[ptr2];
            ptr2++;
        }
        
        if((n1+n2)%2) return curr;
        return (curr+prev)/2.0;
        
    }
};