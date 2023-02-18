//TC-->O(n*log(D)) where D is the difference between maxSum-minSum i.e. search space

class Solution {
private:
    const int mod = 1000000000 + 7;
    int minSum = 0;
    int maxSum = 0;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        minSum=*min_element(begin(nums),end(nums));
        maxSum=accumulate(begin(nums),end(nums),0);
        
        int LthSortedSum=findKthSortedSum(nums,(left-1)-1);
        int RthSortedSum=findKthSortedSum(nums,right-1);
        
        int lPreSum=preSumInSortedSums(nums,LthSortedSum);
        int rPreSum=preSumInSortedSums(nums,RthSortedSum);
        
        int extraLthSortedSum=countSortedSumsUnder(nums,LthSortedSum)-(left-1);
        int extraRthSortedSum=countSortedSumsUnder(nums,RthSortedSum)-(right);
        
        lPreSum-=(extraLthSortedSum*LthSortedSum);
        rPreSum-=(extraRthSortedSum*RthSortedSum);
        
        return rPreSum-lPreSum;
    }
    
    int findKthSortedSum(vector<int>&nums,int k){
        if(k<0) return 0;
        int low=minSum,end=maxSum+1; //why +1 here
        
        while(low<end){
            int mid=low+(end-low)/2;
            
            int val=countSortedSumsUnder(nums,mid);
            
            if(val<k+1) low=mid+1; //and why k+1 here
            else end=mid;
        }
        return low;
    }
    
    int countSortedSumsUnder(vector<int>& nums,int x){
        int count=0,subSum=0,r=0;
        for(int l=0;l<nums.size();l++){
            while(r<nums.size() && subSum+nums[r]<=x){
                subSum+=nums[r];
                r++;
            }
            count+=(r-l);
            subSum-=nums[l];
        }
        return count;
    }
    
    int preSumInSortedSums(vector<int>& nums,int x){
        int rowSum=0,subSum=0,totalRowSum=0,r=0;
        for(int l=0;l<nums.size();l++){
            while(r<nums.size() && subSum+nums[r]<=x){
                subSum+=nums[r];
                rowSum+=subSum;
                r++;
            }
            totalRowSum+=rowSum;
            totalRowSum%=mod;
            
            subSum-=nums[l];
            rowSum-=((r-l)*nums[l]);
        }
        
        return totalRowSum;
    }
};