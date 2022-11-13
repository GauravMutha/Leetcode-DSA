class Solution {
public:
    int minSwaps(string s) {
       int closed=0,open=0;
        for(auto c:s){
            if(c=='[') open++;
            else if(c==']' && open<=0) closed++;
            else if(c==']' && open>0) open--;
        }
        return (closed+1)/2;
    }
};

//Solution 1: formula + WITHOUT stack
//TC -> O(n) SC->O(1) 