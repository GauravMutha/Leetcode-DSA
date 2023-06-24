//Slight Modification to count inversions in array
//A bit different way for pair count
class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int>temp;
        int i=low , j=mid+1, count=0;
        //below is the function to count the pairs
         for(i=low;i<=mid;i++){
            while( j<=high && nums[i]>(2 *(long long)nums[j])) j++;
            count+=(j-(mid+1));
        }
        
        i=low , j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid) temp.push_back(nums[i]) , i++;
        while(j<=high) temp.push_back(nums[j]) , j++;

        for(int i=low;i<=high;i++) nums[i]=temp[i-low];

        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high)
    {
        int count=0;
        if(low>=high) return 0;

        int mid=low+(high-low)/2;

        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};