class Solution {
public:
    int scoreOfParentheses(string s) {
        int curr=0;
        stack<int>st;
        for(auto c: s){
            if(c=='('){
                st.push(curr);
                curr=0;
            }
            else{
                curr=st.top()+ max(curr*2,1);
                st.pop();
            }
        }
        return curr;
    }
};

//Using stack
//SC-->O(n)
//TC-->O(n)