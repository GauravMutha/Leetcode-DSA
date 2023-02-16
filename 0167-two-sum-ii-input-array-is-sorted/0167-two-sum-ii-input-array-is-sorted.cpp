//binary search
//TC-->O(n*log(n))
class Solution {
private :
    int binarySearch(int i,long require,vector<int>& nums){
        int start=i ,end=nums.size()-1 ,j=-1;
        
        while(start<=end){
            int mid=start  +(end-start)/2;
            
            if(nums[mid]<=require){
                if(nums[mid]==require) j=mid;
                start=mid+1;
            }
            else if(nums[mid]>require) end=mid-1;
        }
        
        return j;
    }
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int j=binarySearch(i,long(k-nums[i]),nums);
            if(j!=-1 && j!=i) return vector<int>({i+1,j+1});
        }
        
        return {};
    }
};