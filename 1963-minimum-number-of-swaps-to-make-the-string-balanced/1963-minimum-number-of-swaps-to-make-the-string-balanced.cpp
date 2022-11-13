class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        for(auto c:s){
            if(c=='[') st.push(c);
            else if(!st.empty() && c==']') st.pop(); 
        }
        return (st.size()+1)/2;
    }
};

//Solution 1: formula + stack
//TC -> O(n) SC->O(n)