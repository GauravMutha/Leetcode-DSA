class Solution {
public:
    int pre(char c){
        if(c=='*' || c=='/') return 1;
        return 0;
    }
    string toPostFix(string s){
        stack<char>st;
        string post;
        for(auto c : s){
            if(c==' ') continue;
            else if(isdigit(c)) post+=c;
            else{
                post+='|';
                while(!st.empty() && pre(c)<=pre(st.top()))
                    post+=st.top() , st.pop();
                st.push(c);
            }
            
        }
        post+='|';
        while(!st.empty()) post+=st.top() , st.pop();
        return post;
    }
    int calculate(string s) {
        s=toPostFix(s);
        stack<int>st;
        int n1=0,n2=0;
        for(int i=0;i<size(s);i++){
            if(isdigit(s[i])){
                int curr=0;
                while(i<size(s) && isdigit(s[i]))
                    curr=curr*10 + (s[i++]-'0');
                st.push(curr);                
            }
            else{
                n1=st.top() ,st.pop();
                n2=st.top(),st.pop();
                if(s[i]=='+') st.push(n2+n1);
                else if(s[i]=='-') st.push(n2-n1);
                else if(s[i]=='*') st.push(n2*n1);
                else if(s[i]=='/') st.push(n2/n1);
            }
        }
        return st.top();
    }
};
//Using Stack
//SC-->O(N)
//TC-->O(N)