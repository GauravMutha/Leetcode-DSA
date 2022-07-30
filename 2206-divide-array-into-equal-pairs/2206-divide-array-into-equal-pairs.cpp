class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //TC--->O(n)
        int n=*max_element(nums.begin(),nums.end());
        vector<int>counter(n+1,0);
        
        for(int i=0;i<nums.size();i++){
            counter[nums[i]]++;
        }
        
        for(int i=0;i<n+1;i++){
            if(counter[i]%2!=0){
                return false;
            }
        }
        return true;
    }
};