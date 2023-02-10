//search first positive and last negative
//considering zero as positive in first search and negtive in seond search
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int start=0 ,end=nums.size()-1,mid=0,firstPos=0,lastNeg=0;
        if(nums[start]==0 && nums[end]==0) return 0;
        //first positive number
        while(start<=end){
           mid = start + (end-start)/2;
            
            if(nums[mid]>0) firstPos=mid , end=mid-1; 
            else  start=mid+1;  
        }
        start=0 ,end=nums.size()-1;
        //first negative number
        while(start<=end){
            mid = start + (end-start)/2;
            
            if(nums[mid]<0)  lastNeg=mid , start=mid+1;
            else  end=mid-1;   
        }
        
        return max(((int)nums.size()-firstPos),(lastNeg+1));
    }
};