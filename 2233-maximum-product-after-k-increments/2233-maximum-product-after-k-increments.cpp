//prority queue min heap
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minh(begin(nums),end(nums));
        long mod=1e9 +7 ,res=1;
        while(k--){
            int x=minh.top();
            minh.pop();
            minh.push(x+1);
        }
        
        if(minh.top()==0) return 0;
        
        while(!minh.empty()){
            res=res*minh.top()%mod , minh.pop();
        }
        return (int)res;
    }
};