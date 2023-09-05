class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        
        vector<int>count(31,0);
        long long sum=0;
        
        
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            count[(int)(log2(x))]++;
            sum+=x;
        }
        if(sum<target) return -1;
        
        int i=0,res=0;
        while(i<30){
            if((1<<i)&target){
                if(count[i]>0) count[i]--;
                else{
                    int j=i;
                    while(j<30 && count[j]==0) j++, res++;
                    count[j]--;
                    j--;
                    while(j>i) count[j]++, j--;
                }
            }
            count[i+1]+=count[i]/2;
            i++;
        }
        return res;
    }
};