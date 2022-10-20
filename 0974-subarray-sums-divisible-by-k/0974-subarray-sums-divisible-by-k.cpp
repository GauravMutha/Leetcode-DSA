class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m{{0,1}};
        int sum=0,res=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int re=sum%k;
            if(re<0) re+=k;
            
            if(m.count(re)) res+=m[re];
            
            m[re]++;
        }
        
        return res;
    }
};

//prefix sum technique