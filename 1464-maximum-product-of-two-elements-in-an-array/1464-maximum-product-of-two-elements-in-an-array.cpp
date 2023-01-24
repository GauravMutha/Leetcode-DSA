//Priority Queue -- O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=1;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(auto e : nums){
            minh.push(e);
            if(minh.size()>2) minh.pop();
        }
        while(!minh.empty())
            ans*=(minh.top()-1) , minh.pop();
        
        return ans;
    }
};