//Priority queue min heap top k concept
typedef priority_queue<int,vector<int>,greater<int>>pq;
class Solution {
public:
    int sumOfDig(int n){
        int sum=0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,pq> m;
        int res=INT_MIN , x1=0 ,x2=0;
        for(auto &num : nums){
            int sum=sumOfDig(num);
            m[sum].push(num);
            if(m[sum].size()>2) m[sum].pop();
        }
        
        for(auto &[sum,h]:m){
            if(h.size()<2) continue;
            x1=h.top(), h.pop();
            x2=h.top(), h.pop();
            res=max(res,x1+x2);
        }
        
        return (res==INT_MIN)? -1 : res;
    }
};