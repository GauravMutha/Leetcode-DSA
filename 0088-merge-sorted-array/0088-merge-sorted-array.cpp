//Two pointers
//Constant space
//O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //ptr3 starts on num1 , from the end
        int ptr1=m-1, ptr2=n-1 , ptr3=m+n-1;
        
        while(ptr1>=0 && ptr2>=0){
            if(nums1[ptr1]>=nums2[ptr2]){
                nums1[ptr3]=nums1[ptr1];
                ptr1--;
            }
            else{
                nums1[ptr3]=nums2[ptr2];
                ptr2--;
            }
            ptr3--;
        }
        
        /*when ptr2 has gone out of bound
        and ptr1 is still remaining then
        ptr1 =ptr3 so no need for managing
        that condition*/
        
        while(ptr2>=0){
            nums1[ptr3]=nums2[ptr2];
            ptr3--;
            ptr2--;
        }
        return;
    }
};