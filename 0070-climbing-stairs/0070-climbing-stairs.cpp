//Tabulation(bottom up)
//solving from lowest subproblem (final stair =0) to higher subproblems
//removes the need for dp array
//TC-->O(n)
//SC-->O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int last=1,secondLast=1,curr=0;
        for(int i=2;i<=n;i++){
            curr=last+secondLast;
            secondLast=last;
            last=curr;
        }
        
        return curr;
    }
};