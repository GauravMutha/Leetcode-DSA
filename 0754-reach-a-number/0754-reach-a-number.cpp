//Without loop
//pure math using formula
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        long long n=ceil((sqrt(1.0+8.0*target)-1.0)/2);
        long long nSum=(n*(n+1))/2;
        
        long long diff=nSum-target;
        
        if(diff%2==0) return (int)n;
        
        else if(n%2==0) return (int)n+1;
        else  return n+2;
    }
};