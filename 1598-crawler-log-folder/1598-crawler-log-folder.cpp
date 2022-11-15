class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(auto oper : logs){
            if(oper=="../"){
                if(!st.empty()) st.pop();
            }
            else if(oper!="./") st.push(oper);
        }
        return st.size();
    }
};