class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>m(k,0);
        int sum=0,res=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int re=sum%k;
            if(re<0) re+=k;
            
            if(m[re]!=0) res+=m[re];
            
            m[re]++;
        }
        
        return res;
    }
};

//prefix sum technique- using array for mapping