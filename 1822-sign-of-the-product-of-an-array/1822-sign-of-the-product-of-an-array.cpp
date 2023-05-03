class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool neg=true;
        for(auto &num : nums){
            if(num==0) return 0;
            if(num<0) neg=!neg;
        }
        return (neg==false)?-1:1;
    }
};