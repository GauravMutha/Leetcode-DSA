//With loop
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0,step=0;
        while(sum<target){
            step++;
            sum+=step;
        }
        while((sum-target)%2!=0){
            step++,
            sum+=step;
        }
        
        return step;
    }
};