class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tn=-1,tnp1=0,tnp2=0;
        
        for(int i=0;i<nums.size();i++){
            int cwtn=tn & nums[i];
            int cwtnp1=tnp1 & nums[i];
            int cwtnp2=tnp2 & nums[i];
            
            tn=tn & (~cwtn);
            tnp1=tnp1 | cwtn;
            
            tnp1=tnp1 & (~cwtnp1);
            tnp2=tnp2 | cwtnp1;
            
            tnp2=tnp2 & (~cwtnp2);
            tn=tn | cwtnp2;
        }
        return tnp1;
    }
};
//TC--->O(n)
//SC--->O(1)