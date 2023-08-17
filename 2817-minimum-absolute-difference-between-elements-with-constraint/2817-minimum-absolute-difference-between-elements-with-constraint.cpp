class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        set<int>st;
        int res=INT_MAX,val1=0,val2=INT_MAX;
        
        
        for(int i=x;i<nums.size();i++){
            
            st.insert(nums[i-x]);
            
            auto it1=st.lower_bound(nums[i]),it2=it1;
            
            if( it1==st.end() || (it1!=st.begin() && (*it1)>nums[i]))
                it2=prev(it1);
            
            val1=abs(nums[i]-(*it1));
            val2=abs(nums[i]-(*it2));
            
            res=min({val1,val2,res});
            
        }
        
        return res;
    }
};