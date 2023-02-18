//Binary search
//O(n*log(D)) D is the search space i.e. difference between minimum and maximum elements of given array
class Solution {
private: 
    int validate(vector<int>&arr , int minDay,int m,int required){
        int flowerCount=0,bouquets=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=minDay) flowerCount++;
            else flowerCount=0;
            
            if(flowerCount==required) bouquets++ , flowerCount=0;
        }
        if(bouquets>=m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k > bloomDay.size()) return -1;
        int low=*min_element(begin(bloomDay),end(bloomDay));
        int high=*max_element(begin(bloomDay),end(bloomDay));
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(validate(bloomDay,mid,m,k))
                ans=mid , high=mid-1;
            else low=mid+1;
        }
        
        return ans;
    }
};