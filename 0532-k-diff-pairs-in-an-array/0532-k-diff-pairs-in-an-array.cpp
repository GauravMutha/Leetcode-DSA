// sort+map
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count=0,n=nums.size();
        for(int i=0;i<n;i++) m[nums[i]]++;
        
        for(auto &[key,value] : m){
            if(k==0) count+=(value>1);
            else count+=(m.find(key+k)!=m.end());
        }
        
        return count;
    }
};