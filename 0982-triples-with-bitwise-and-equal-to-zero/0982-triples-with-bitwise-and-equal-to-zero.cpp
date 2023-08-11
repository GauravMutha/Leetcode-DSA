class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int>m;
        int res=0;
        for(auto a:nums){
            for(auto b:nums){
                m[a&b]++;
            }
        }
        
        for(auto a:nums){
            for(auto &[p,freq]:m){
                if((a&p)==0) res+=freq;
            }
        }
        
        return res;
    }
};