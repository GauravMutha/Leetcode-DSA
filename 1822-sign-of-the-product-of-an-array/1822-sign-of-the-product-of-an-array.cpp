class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntPos=0,cntNeg=0;
        for(auto &num : nums){
            if(num==0) return 0;
            cntNeg+=(num<0);
        }
        return (cntNeg%2)?-1:1;
    }
};