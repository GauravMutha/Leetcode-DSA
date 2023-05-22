//Recursive
class Solution {
public:
    double helper(double x, int n){
        if(n==0) return 1;
        if((n%2)==0){
            return helper(x*x,n/2);
        }
        else return x*helper(x*x,n/2);
    }
    double myPow(double x, int n) {
        double ans=1.0;
        if(n<0){
            ans=helper(x,n);
            return (double)(1.0)/(double)(ans);
        }
        
        return helper(x,n);
    }
};

