//priority queue min heap
//TC-->O(n^2log(n)) //and not right*log(n) because right can be n
//SC-->O(n)
typedef pair<int,int>p;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=0,mod=1e9+7;
        priority_queue<p,vector<p>,greater<p>> minh;
        for(int i=0;i<n;i++){
            minh.push({nums[i],i+1});
        }
        for(int i=1;i<=right;i++){
            auto x= minh.top();
            minh.pop();
            
            if(i>=left) ans=(ans+x.first)%mod;
            
            if(x.second<n) {
                x.first+=nums[x.second];
                x.second++;
                
                minh.push({x});
            }
        }
        
        return ans;
        
    }
};