class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1,mid=0;
        
        while(start<=end){
            mid=start+ (end-start)/2;
            
            if((mid-1)<0) return end;
            else if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
                return mid;
            
            if(arr[mid-1] <arr[mid] && arr[mid+1]>arr[mid])
                start=mid+1;
            else if(arr[mid-1]>arr[mid] && arr[mid+1]<arr[mid])
                end=mid-1;
        }
        
        return -1;
    }
};