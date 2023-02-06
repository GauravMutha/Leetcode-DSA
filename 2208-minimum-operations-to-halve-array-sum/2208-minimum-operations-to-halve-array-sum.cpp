//max heap
class Solution {
public:
    int halveArray(vector<int>& nums) {
        int op=0 ;
        double k=0,val=0, sum=0;
        priority_queue<double>maxh;
        
        for(auto num : nums) maxh.push(num) , sum+=num;
        
        k=sum/2.0;
        
        while(sum>k){
            op++;
            val=maxh.top();
            maxh.pop();
            sum-=val/2.0;
            val/=2.0;
            maxh.push(val);
        }
        
        return op;
    }
};