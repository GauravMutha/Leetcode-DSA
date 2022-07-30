class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //TC--->O(nlogn)
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        for(auto it:m){
            if(it.second%2!=0)return false;
        }
        
        return true;
    }
};