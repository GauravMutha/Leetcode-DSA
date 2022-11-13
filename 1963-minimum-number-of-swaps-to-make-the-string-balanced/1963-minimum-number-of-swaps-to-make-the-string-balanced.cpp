class Solution {
public:
    int minSwaps(string s) {
       int ans=0,balance=0;
        for(auto c:s){
            if(c=='[') balance++;
            else balance--;
            if(balance<0) {
                ans++;
                balance=1;
            }
        }
        return ans;
    }
};

//Solution 2: Two pointers
//TC -> O(n) SC->O(1) 