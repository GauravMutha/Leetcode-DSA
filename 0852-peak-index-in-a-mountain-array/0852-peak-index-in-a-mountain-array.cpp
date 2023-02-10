//concise than previous solution
//we can remove the first and last element by setting our start and end values in that manner
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=1,end=arr.size()-2,mid=0;
        
        while(start<=end){
            mid=start+ (end-start)/2;
            
            if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
                return mid;
            
            if(arr[mid-1] <arr[mid] && arr[mid+1]>arr[mid])
                start=mid+1;
            else if(arr[mid-1]>arr[mid] && arr[mid+1]<arr[mid])
                end=mid-1;
        }
        
        return -1;
    }
};