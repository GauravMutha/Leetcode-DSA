class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res(2,0);
        long int diff=0;
        for(auto ele:nums){
            diff^=ele;
        }
        diff &= -(diff);
        
        for(auto ele:nums){
            if((diff&ele)>0)res[0]^=ele;
            else res[1]^=ele;
        }
        return res;
    }
};

//TC--->O(n)
//SC--->O(1)