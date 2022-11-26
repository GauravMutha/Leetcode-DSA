class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        long long ans=0,n1=0,n2=0,n3=0;
        stack<long long>st;
        for(auto &str:tokens){
            if(str=="+" || str=="-" || str=="/" || str=="*"){
                n1=st.top() ,st.pop();
                n2=st.top() ,st.pop();
                if(str=="+") n3=n2+n1;
                else if(str=="-") n3=n2-n1;
                else if(str=="*") n3=n2*n1;
                else if(str=="/") n3=n2/n1;
                st.push(n3);
            }            
            else st.push(stoll(str));

        }
        return (int)st.top();
    }
};