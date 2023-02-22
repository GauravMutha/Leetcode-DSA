//Two pointers
//O(Nlog(N) + N^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        sort(begin(nums),end(nums));
        for(int k=2;k<nums.size();k++){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]) 
                    count+=(j-i) ,j--;
                else i++;
            }
        }
        return count;
    }
};