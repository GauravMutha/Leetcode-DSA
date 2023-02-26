//Binary search
//O(n*log(k)) k is max(arr)
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low,high,sum=0,n=arr.size(),maxElement=-1;
        for(int i=0;i<arr.size();i++) 
            sum+=arr[i] , maxElement=max(maxElement,arr[i]);
        
        if(sum<=target) return maxElement;
        
        low=1,high=maxElement;
        
        while(low<high){
            int mid=low+(high-low)/2;
            sum=0;
            for(int i=0;i<arr.size();i++)
                sum+=min(arr[i],mid);
            if(sum>=target) high=mid;
            else low=mid+1;
        }
        //for low-1, sum  can be closer than for low (in case low sum!= target)
        int s1=0,s2=0;
        for(int i=0;i<n;i++) s1+=min(arr[i],low) , s2+=min(low-1,arr[i]);
        return (abs(target-s2)<=abs(target-s1)) ? low-1 : low;
        
        return low;
    }
};