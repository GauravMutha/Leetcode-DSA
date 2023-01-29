//Priority Queue min heap
typedef pair<int,int>p;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>res;
        priority_queue<p,vector<p>,greater<p>>minh;
        
        for(int i=0;i<nums.size();i++){
            minh.push({nums[i],i});
            if(minh.size()>k){
                nums[minh.top().second]=INT_MIN;
                 minh.pop();
            }
        }
        for(auto &e : nums) if(e!=INT_MIN) res.push_back(e);
        
        return res;
    }
};