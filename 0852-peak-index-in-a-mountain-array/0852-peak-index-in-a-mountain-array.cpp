// another concise solution for handling out of bound edge cases faced in first wrong solution of this problem
//handled better than 1st accepted solution
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1,mid=0;
        
        while(start<=end){
            mid=start+ (end-start)/2;
            if((mid-1)>=0 && arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
                return mid;
            if(arr[mid+1]>arr[mid])
                start=mid+1;
            else if(arr[mid+1]<arr[mid]) 
                end=mid-1;
        }
        
        return -1;
    }
};