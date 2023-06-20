//Two pass O(N)
//SC->O(N)
//Count sort like
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>hash(3,0);
        for(int i=0;i<n;i++) hash[nums[i]]++;
        
        for(int i=0;i<n;i++){
            if(hash[0]) nums[i]=0 ,hash[0]--;
            else if(hash[1]) nums[i]=1 ,hash[1]--;
            else if(hash[2]) nums[i]=2 ,hash[2]--;
        }
        return;
    }
};