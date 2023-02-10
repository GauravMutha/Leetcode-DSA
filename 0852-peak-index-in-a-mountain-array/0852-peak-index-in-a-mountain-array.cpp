//we let the bs flow
//we know that once we have start==end we have our answer but we still let bs run
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1,mid=0;
        
        while(start<=end){
            mid=start+ (end-start)/2;
             
            if(arr[mid+1]>arr[mid])
                start=mid+1;
            else if(arr[mid+1]<arr[mid]) 
                end=mid-1;
        }
        
        return start;
    }
};