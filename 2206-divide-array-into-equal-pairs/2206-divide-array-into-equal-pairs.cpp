class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int pairs=0;
        int n=nums.size()/2;
        for(int i=0;i<2*n-1;i++){
            if(nums[i]==-1)continue;
            for(int j=i+1;j<2*n;j++){
                if(nums[j]==-1)continue;
                else if(nums[i]==nums[j]){
                    pairs++;
                    nums[j]=-1;
                    break;
                }
            }
        }
        return (pairs==n)?true:false;
    }
};