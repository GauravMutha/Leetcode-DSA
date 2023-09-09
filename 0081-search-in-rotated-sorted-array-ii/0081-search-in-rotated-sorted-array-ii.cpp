// striver sheet
//taking pivot concept
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.back()==target || nums[0]==target) return true;
        
        int sz=nums.size();
        int l=0,r=sz-1;
        
        //trimming search space
        while(l+1<sz && nums[l]==nums[0]) l++;
        if(l==(sz-1)) return (nums[0]==target);
        
        while(r>=0 && nums[r]==nums[r-1]) r--; 
        
        //find pivot
        int start=l, end=r, pivot=-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums.back()) l=mid+1;
            else r=mid;
        }
        pivot=l;
        //find the correct half to search into
        if(pivot==-1) l=start, r=end; //there is no half
        else {
            if(target>nums[end]) l=start, r=pivot-1;
            else l=pivot, r=end;
        }
        
        // normal binary search
        while ( l <= r ){
            int mid = l + (r-l)/2;
            if( nums[mid] > target ) r = mid-1;
            else if( nums[mid] < target ) l = mid+1;
            else return true;
        }
        
        return false;
    }
};