//Two pointer
//Not in place
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n,0),left,right;
        for(int i=0,j=n,k=0;j<2*n;i++,j++){
            ans[k]=nums[i];
            k++;
            ans[k]=nums[j];
            k++;
        }
        
        return ans;
    }
};