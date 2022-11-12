class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st; 
        for(auto c : s){
            if(c=='(') st.push(c);
            else{
                if(st.empty()) count++;
                else st.pop();
            }
         }
        return (st.size() + count);
    }
};